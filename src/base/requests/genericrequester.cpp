/// @file genericrequester.cpp
/// @brief Implementation of GenericRequester
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

#include "genericrequester.hpp"
#include "../parsers/jsonparser.hpp"
#include "../utils/librtconstants.hpp"

using LibRT::RequestResult;
using LibRT::ResponseInfos;
using LibRT::HTTPRequestType;
using LibRT::NetworkResponse;
using LibRT::CommunicatorManager;
using LibRT::NetworkResultType;
using LibRT::Communicator;
using LibRT::ArgsMap;
using LibRT::HeadersMap;
using LibRT::GetArgs;
using LibRT::HTTPArgs;

// Constructor. It just calls the parent constructor.
LibRT::GenericRequester::GenericRequester(HTTPRequestType type,
										  QString url,
										  NetworkResultType parseError,
										  QNetworkAccessManager &netManager,
										  QByteArray reqType) :
	QObject(),
	uuid(QUuid::createUuid()),
	requestURL(url),
	requestType(type),
	contentType(reqType),
	network(netManager),
	parsingErrorType(parseError)
{}


// Destructor
LibRT::GenericRequester::~GenericRequester() {}

// Entity managing communicators
CommunicatorManager LibRT::GenericRequester::communicatorManager = CommunicatorManager();


/////////////
// Getters //
/////////////

// Getter on the requester's UUID
QUuid LibRT::GenericRequester::getUuid() {
	return uuid;
}

// Setting parsingErrorType
void LibRT::GenericRequester::setParsingErrorType(NetworkResultType parseErrorType) {
	parsingErrorType = parseErrorType;
}


/////////////////////////////
// Communicator management //
/////////////////////////////

// Removing a requester of the Communicator manager
void LibRT::GenericRequester::removeCommunicator(Communicator * weblink) {
	if (weblink) {
		disconnect(weblink, &Communicator::requestDone,
				   this, &GenericRequester::treatResults);

		communicatorManager.removeCommunicator(weblink);
	}
}

// Executing the low level network request.
void LibRT::GenericRequester::executeNetworkRequest(HeadersMap headers,
													GetArgs getParameters,
													HTTPArgs postParameters)
{
	Communicator * weblink = new Communicator(requestURL,
											  requestType,
											  headers,
											  getParameters,
											  postParameters,
											  network);

	connect(weblink, &Communicator::requestDone,
			this, &GenericRequester::treatResults);

	communicatorManager.addCommunicator(weblink);

	weblink->executeRequest();
}


///////////////////////////
// Executing the request //
///////////////////////////

// Building GET Parameters
ArgsMap LibRT::GenericRequester::buildGETParameters() {
	return ArgsMap();
}

// Building POST Parameters
ArgsMap LibRT::GenericRequester::buildPOSTParameters() {
	return ArgsMap();
}

// Building the GET arguments builder
GetArgs LibRT::GenericRequester::buildGETArgs() {
	return GetArgs(buildGETParameters());
}

// Building the POST arguments builder
HTTPArgs LibRT::GenericRequester::buildPOSTArgs() {
	return HTTPArgs(buildPOSTParameters());
}

// Building HTTP Headers
HeadersMap LibRT::GenericRequester::buildHTTPHeaders(ArgsMap getParameters,
													 ArgsMap postParameters)
{
	Q_UNUSED(getParameters)
	Q_UNUSED(postParameters)

	HeadersMap headers;

	// Content type
	headers.insert("Content-Type", this->contentType);

	return headers;
}

// Executing the request
void LibRT::GenericRequester::executeRequest() {
	GetArgs getParameters = buildGETArgs();
	HTTPArgs postParameters = buildPOSTArgs();
	HeadersMap headers = buildHTTPHeaders(getParameters.getHttpArgs(),
										  postParameters.getHttpArgs());

	// Request time !
	this->executeNetworkRequest(headers, getParameters, postParameters);
}


//////////////////////////
// Treatment of results //
//////////////////////////

// Slot executed when the Twitter Communicator has just finished its work.
void LibRT::GenericRequester::treatResults(NetworkResponse netResponse) {
	// Deleting the Communicator
	this->removeCommunicator(qobject_cast<Communicator *>(sender()));

	do_treatResults(netResponse);
}

// Slot executed when the Twitter Communicator has just finished its work.
void LibRT::GenericRequester::do_treatResults(NetworkResponse netResponse) {
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
			// Parsing the response and filling requestResult
			bool parseOK;
			QVariantMap parseErrorMap;
			requestResult.parsedResult = this->parseResult(netResponse,
														   parseOK,
														   parseErrorMap);
			requestResult.parsingErrors.code = parseErrorMap.value("lineError").toInt();
			requestResult.parsingErrors.message = parseErrorMap.value("errorMsg").toString();

			if (parseOK) {
				// Other treatments related to the service
				requestResult.serviceErrors = this->treatServiceErrors(requestResult.parsedResult,
																	   netResponse);
				// Updating the NetworkResultType with service errors
				requestResult.resultType = requestResult.serviceErrors.isEmpty() ?
							NO_REQUEST_ERROR
						  : SERVICE_ERRORS;
			} else {
				requestResult.resultType = parsingErrorType;

				// Giving the response just in case the user would like to do sthg with it.
				requestResult.parsedResult = QVariant::fromValue(netResponse.getResponseBody());
			}
		} break;
	}

	// Telling the Calls that the request is finished
	emit requestDone(requestResult);
}
