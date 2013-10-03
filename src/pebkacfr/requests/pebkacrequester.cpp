/// @file pebkacrequester.cpp
/// @brief Implementation of PebkacRequester
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2013 Romain Ducher
///
/// This file is part of LibRT.
///
/// LibRT is free software: you can redistribute it and/or modify it under
/// the terms of the GNU Lesser General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// LibRT is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
/// for more details.
///
/// You should have received a copy of the GNU Lesser General Public License
/// along with LibRT. If not, see <http://www.gnu.org/licenses/>.

#include "pebkacrequester.hpp"

#include <QStringList>
#include <QRegularExpression>
#include <QVariantList>
#include "../../base/networkresulttype.hpp"
#include "../../base/parsers/jsonparser.hpp"
#include "../../base/parsers/xmlparser.hpp"
#include "patterngetargs.hpp"

namespace PEBKAC = LibRT::Pebkac;

using LibRT::ArgsMap;
using LibRT::GenericRequester;
using LibRT::GetArgs;
using LibRT::HeadersMap;
using LibRT::HTTPRequestType;
using LibRT::JSONParser;
using LibRT::NetworkResponse;
using LibRT::RequestResult;
using LibRT::ResponseInfos;
using LibRT::XMLParser;
using PEBKAC::PatternGetArgs;
using PEBKAC::PebkacAuthenticator;

// Constructor
PEBKAC::PebkacRequester::PebkacRequester(HTTPRequestType type,
										 QString url,
										 const PebkacAuthenticator & authPebkac,
										 QNetworkAccessManager & netManager) :
	GenericRequester(type, url, authPebkac.getOutputFormat(), netManager),
	pebkacAuth(authPebkac),
	pattern("")
{}

// Destructor
PEBKAC::PebkacRequester::~PebkacRequester() {}

//////////////////////////////////
// GenericRequester overridings //
//////////////////////////////////

// Building HTTP headers
HeadersMap PEBKAC::PebkacRequester::buildHTTPHeaders(ArgsMap getParameters,
													 ArgsMap postParameters)
{
	HeadersMap headers = GenericRequester::buildHTTPHeaders(getParameters,
															postParameters);

	// User Agent
	headers.insert("User-Agent", pebkacAuth.getUserAgent());
	headers.insert("Api-Auth-Token", pebkacAuth.getAPIKey());

	return headers;
}

// Building getParameters
ArgsMap PEBKAC::PebkacRequester::buildGETParameters() {
	ArgsMap getArgs = GenericRequester::buildGETParameters();

	pattern = "";

	return getArgs;
}

// Building the GET arguments builder.
GetArgs PEBKAC::PebkacRequester::buildGETArgs() {
	return PatternGetArgs(buildGETParameters(), pattern);
}

// Treat results
void PEBKAC::PebkacRequester::do_treatResults(NetworkResponse netResponse) {
	RequestResult requestResult;

	// Looking the HTTP request
	ResponseInfos netHTTPRep = netResponse.getHttpResponse();
	requestResult.httpResponse = netHTTPRep;
	requestResult.errorMessage = netResponse.getRequestError();

	switch (netHTTPRep.code) {
		case INVALID_HTTP_CODE:
			// Invalid response => INVALID_RESULT
			requestResult.resultType = INVALID_RESULT;
			break;

		case TIMEOUT_HTTP_CODE:
			// No response (because of timeout) => API_CALL
			requestResult.resultType = API_CALL;
			break;

		default: {
			QByteArray rawResponse = netResponse.getResponseBody();

			if (responseIsError(rawResponse)) {
				// Giving the response just in case the user would like to do sthg with it.
				requestResult.parsedResult = QVariant::fromValue(netResponse.getResponseBody());

				// It is a service error. Fill the corresponding field
				requestResult.serviceErrors = this->treatServiceErrors(requestResult.parsedResult,
																	   netResponse);

				// Updating the NetworkResultType with service errors
				requestResult.resultType = SERVICE_ERRORS;
			} else {
				// Result is OK. Parse it !
				bool parseOK;
				QVariantMap parseErrorMap;
				requestResult.parsedResult = this->parseResult(netResponse,
															   parseOK,
															   parseErrorMap);
				requestResult.parsingErrors.code = parseErrorMap.value("lineError").toInt();
				requestResult.parsingErrors.message = parseErrorMap.value("errorMsg").toString();

				if (parseOK) {
					requestResult.resultType = NO_REQUEST_ERROR;
				} else {
					requestResult.resultType = parsingErrorType;

					// Giving the response just in case the user would like to do sthg with it.
					requestResult.parsedResult = QVariant::fromValue(netResponse.getResponseBody());
				}
			}
		} break;
	}

	// Telling the Calls that the request is finished
	emit requestDone(requestResult);
}

// Workaround for this bug : https://bugreports.qt-project.org/browse/QTBUG-32524
// TODO quand passage à Qt 5.1.2 : remove those 3 #include as soon as the bug is fixed
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

// Parse the raw results of the request.
QVariant PEBKAC::PebkacRequester::parseResult(NetworkResponse results,
											  bool & parseOK,
											  QVariantMap & parsingErrors)
{
	QVariant result;

	// Variables for parsers
	QString errorMsg;
	int lineMsg;
	QStringList errList;

	switch (parsingErrorType) {
		case LibRT::JSON_PARSING: {
			// For JSON outputs. Same as Twitter.
			JSONParser parser;

			// TODO : improve it because of improved JSONParser
			QJsonValue parseval = parser.parse(results.getResponseBody(),
											   &parseOK, &errorMsg,
											   &lineMsg);

			if (!errorMsg.isEmpty()) {
				errList.append(errorMsg);
			}

			// Workaround for this bug : https://bugreports.qt-project.org/browse/QTBUG-32524
			// TODO quand passage à Qt 5.1.2 : remove it as soon as the bug is fixed
			switch (parseval.type()) {
				case QJsonValue::Object: {
					// Is the QJsonObject empty ?
					QJsonObject o = parseval.toObject();
					if (o.isEmpty()) {
						// Buggy case
						QVariantMap varmap;
						result = QVariant::fromValue(varmap);
					} else {
						result = parseval.toVariant();
					}
				} break;

				case QJsonValue::Array: {
					// Is the QJsonArray empty ?
					QJsonArray a = parseval.toArray();
					if (a.isEmpty()) {
						// Buggy case
						QVariantList varlist;
						result = QVariant::fromValue(varlist);
					} else {
						result = parseval.toVariant();
					}
				} break;

				default:
					result = parseval.toVariant();
					break;
			}

			// Normal code (when no bug)
			//result = parseval.toVariant();
		} break;

		case LibRT::XML_PARSING:{
			// For XML outputs.
			XMLParser parser;

			QDomElement parseval = parser.parse(results.getResponseBody(),
												&parseOK,
												&errorMsg,
												&lineMsg);

			if (!errorMsg.isEmpty()) {
				errList.append(errorMsg);
			}

			if (parseval.isNull()) {
				// Unexpected NULL XML. For PEBKAC it is a failure.
				parseOK = false;
				errList.append(PebkacRequester::trUtf8("Null XML result."));
				break;
			}

			// Parsing good results

			QString tagRoot = parseval.tagName();

			if (tagRoot == "item") {
				// It is an object. Retrieve it and then put it in a QVariantMap.
				QVariantMap itemMap = this->parseItem(parseval);
				result = QVariant::fromValue(itemMap);
			} else if (tagRoot == "items") {
				// It is a list of objects
				QVariantList itemsList;

				// Scanning all the "item" children elements of the "items" root.
				for (QDomNode it = parseval.firstChild();
					 !it.isNull();
					 it = it.nextSibling())
				{
					QDomElement itemElt = it.toElement();
					QVariantMap itemMap = this->parseItem(itemElt);
					itemsList.append(QVariant::fromValue(itemMap));
				}

				result = QVariant::fromValue(itemsList);
			} else {
				// Unexpected tag. For PEBKAC it is a failure.
				parseOK = false;
				QString failedTagRoot = "";
				failedTagRoot = PebkacRequester::trUtf8("Unexpected XML tag '%1'.").arg(
									tagRoot);
				errList.append(failedTagRoot);
			}
		} break;

		default:
			// Not supposed to happen
			parseOK = false;
			errorMsg = PebkacRequester::trUtf8("Unexpected output format for the PEBKAC API.");
			lineMsg = 0;
			break;
	}

	if (!parseOK) {
		// There was a problem while parsing -> fill the parsingErrors map !
		parsingErrors.insert("errorMsg", QVariant::fromValue(errList.join(' ')));
		parsingErrors.insert("lineError", QVariant::fromValue(lineMsg));
	}

	return result;
}

// Converting a "item" XML element into a QVariantMap.
QVariantMap PEBKAC::PebkacRequester::parseItem(QDomElement item) const {
	// Checks the XML root's tag name.
	if (item.tagName() != "item") {
		// Not a item XML tag. Abort with an empty map.
		return QVariantMap();
	}

	QVariantMap resItem;

	// Scanning all the child renelements of the "item" XML root.
	for (QDomNode it = item.firstChild();
		 !it.isNull();
		 it = it.nextSibling())
	{
		QDomElement itemElt = it.toElement();
		resItem.insert(itemElt.tagName(), itemElt.text());
	}

	return resItem;
}

// Treating parsed results
QList<ResponseInfos> PEBKAC::PebkacRequester::treatServiceErrors(QVariant parsedResults,
																 NetworkResponse netResponse)
{
	Q_UNUSED(parsedResults)
	QString rawResponse = QString::fromUtf8(netResponse.getResponseBody());

	QRegularExpression regex(ERROR_REGEX_PATTERN);

	QRegularExpressionMatch match = regex.match(rawResponse);

	QList<ResponseInfos> serviceErrors;

	// Does the error match with its pattern ? It should.
	if (match.hasMatch()) {
		ResponseInfos serviceError;

		serviceError.code =  match.captured("code").toInt();
		serviceError.message = match.captured("description");

		serviceErrors.append(serviceError);
	}

	return serviceErrors;
}


/////////////////////////
// Error case handling //
/////////////////////////

// Regex for Errors : "^Error\\s\\[AEx(?<code>999|00\\d)\\]\\s\0072\\s(?<description>*)$"
QString PEBKAC::PebkacRequester::ERROR_REGEX_PATTERN = buildErrorRegexPattern();

// Searching for an error
bool PEBKAC::PebkacRequester::responseIsError(const QByteArray rawResponse) const {
	QRegularExpression errRegex(ERROR_REGEX_PATTERN);

	return errRegex.match(QString::fromUtf8(rawResponse)).hasMatch();
}

// Building ERROR_REGEX_PATTERN
QString PEBKAC::PebkacRequester::buildErrorRegexPattern() {
	QString patternNostern = "";

	patternNostern.append('^')
			.append(QRegularExpression::escape("Error ["))
			.append("(?<code>999|00\\d)")
			.append(QRegularExpression::escape("] : "))
			.append("(?<description>*)$");

	// patternNostern == "^Error\\s\\[AEx(?<code>999|00\\d)\\]\\s\0072\\s(?<description>*)$"

	return patternNostern;
}
