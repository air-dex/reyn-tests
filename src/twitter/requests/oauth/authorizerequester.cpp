/// @file authorizerequester.cpp
/// @brief Implementation of AuthorizeRequester
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2011, 2013 Romain Ducher
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

#include "authorizerequester.hpp"

#include <QDomElement>
#include "../../../base/parsers/xmlparser.hpp"
#include "../../../base/utils/connectionutils.hpp"
#include "../../../base/utils/librtconstants.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::NetworkResponse;
using LibRT::ResponseInfos;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::AuthorizeRequester;

// Constructor
// TODO : Change NO_PARSING because of pbms ?
AuthorizeRequester::AuthorizeRequester(const TwitterAuthenticator &authManager,
									   bool forceLog,
									   QString writeLogin,
									   QNetworkAccessManager &netManager) :
	OAuthRequester(GET, AUTHORIZE_URL, authManager, NO_PARSING, netManager),
	forceLogin(forceLog),
	screenName(writeLogin)
{}

// Building GET Parameters
ArgsMap AuthorizeRequester::buildGETParameters() {
	ArgsMap getParameters;

	getParameters.insert("oauth_token",
						 QString::fromLatin1(oauthManager.getOAuthToken().data()));

	getParameters.insert("force_login", boolInString(forceLogin));

	if (screenName != Twitter::FAKE_SCREEN_NAME) {
		getParameters.insert("screen_name", screenName);
	}

	return getParameters;
}

// Parsing results
QVariant AuthorizeRequester::parseResult(NetworkResponse results,
										 bool &parseOK,
										 QVariantMap &parsingErrors)
{
	parsingErrors = QVariantMap();

	// Look at the return code
	if (results.getHttpResponse().code == 200) {
		// It's the HTML page. Send back its code
		QVariantMap resmap;
		resmap.insert("html", QVariant::fromValue(results.getResponseBody()));
		resmap.insert("reply_url", QVariant::fromValue(results.getReplyURL()));
		parseOK = true;
		return QVariant::fromValue(resmap);
	} else {
		// Send an XML error message. Let's get it !
		parsingErrorType = XML_PARSING;

		XMLParser parser;
		QString parseErr;
		bool parseOK;
		int lineErr, colErr;

		QDomElement parsedError = parser.parse(results.getResponseBody(),
											   &parseOK,
											   &parseErr,
											   &lineErr,
											   &colErr);

		if (!parseOK) {
			parsingErrors.insert("errorMsg", parseErr);
			parsingErrors.insert("lineError", QVariant::fromValue(lineErr));
			parsingErrors.insert("columnError", QVariant::fromValue(colErr));
		}

		if (parsedError.tagName() != "hash") {
			return QVariant();
		}

		QVariantMap parsedResults;

		for (QDomElement elt = parsedError.firstChildElement();
			 !elt.isNull();
			 elt = elt.nextSiblingElement())
		{
			parsedResults.insert(elt.tagName(), elt.text());
		}

		return QVariant::fromValue(parsedResults);
	}
}

QList<ResponseInfos> AuthorizeRequester::treatServiceErrors(QVariant parsedResults,
															NetworkResponse netResponse)
{
	QList<ResponseInfos> serviceErrors;

	int httpCodeInt = netResponse.getHttpResponse().code;
	HTTPCode httpCode = HTTPCode(httpCodeInt);

	if (httpCode == LibRT::OK) {
		// If the response code is 200, it is not an error
		return QList<ResponseInfos>();
	} else if (!Twitter::TWITTER_ERROR_CODES.contains(httpCode)) {
		// Unexpected return code
		ResponseInfos error;
		error.code = httpCodeInt;
		error.message = AuthorizeRequester::trUtf8("Unexpected HTTP return code '%1'.").arg(
							QString::number(httpCodeInt));

		serviceErrors.append(error);
	}

	// Error due to code

	// Does the parsed results contain Twitter errors ?
	bool areTwitterErrors = false;
	QVariantMap errmap;

	// Twitter error : 2 fields : "error" and "request" in a QVariantMap

	if (parsedResults.canConvert<QVariantMap>()) {
		errmap = parsedResults.toMap();

		areTwitterErrors = errmap.contains("error") && errmap.contains("request");
	}

	if (areTwitterErrors) {
		ResponseInfos error;
		error.code = httpCodeInt;
		error.message = AuthorizeRequester::trUtf8("Error during the request %1: %2.").arg(
							QString("https://api.twitter.com").append(errmap.value("request").toString()),
							errmap.value("error").toString());

		serviceErrors.append(error);
	}

	return serviceErrors;
}
