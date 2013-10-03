/// @file communicator.cpp
/// @brief Implementation of Communicator.
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2011, 2012, 2013 Romain Ducher
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

#include <QByteArray>
#include <QNetworkRequest>
#include "communicator.hpp"
#include "../utils/connectionutils.hpp"

//#include <QtDebug>		// For debug purposes

using LibRT::ArgsMap;
using LibRT::HeadersMap;
using LibRT::Communicator;
using LibRT::NetworkResponse;
using LibRT::HTTPRequestType;
using LibRT::HeadersMap;
using LibRT::HTTPArgs;
using LibRT::GetArgs;

/////////////
// Coplien //
/////////////

// Constructor
LibRT::Communicator::Communicator(QString url,
								  HTTPRequestType type,
								  HeadersMap headersParam,
								  GetArgs getArgs,
								  HTTPArgs postArgs,
								  QNetworkAccessManager & netManager) :
	QObject(),
	timeoutTimer(),
	serviceURL(url),
	requestType(type),
	getParameters(getArgs),
	postParameters(postArgs),
	headers(headersParam),
	network(netManager)
{
	// Setting the timer
	timeoutTimer.setInterval(10*1000); // 10 seconds
	timeoutTimer.setSingleShot(true);
	connect(&timeoutTimer, &QTimer::timeout,
			this, &Communicator::timeout);
}

// Destructor
LibRT::Communicator::~Communicator() {
	disconnect(&timeoutTimer, &QTimer::timeout,
			   this, &Communicator::timeout);
}


///////////////////////////
// Executing the request //
///////////////////////////

// Preparing the request
QNetworkRequest * LibRT::Communicator::prepareRequest() {
	QUrl requestURL = getParameters.getRequestURL(serviceURL);

	QNetworkRequest * requestToTwitter = new QNetworkRequest(requestURL);

	// Adding the headers
	for (HeadersMap::Iterator it = headers.begin();
		 it != headers.end();
		 ++it)
	{
	   requestToTwitter->setRawHeader(it.key(), it.value());
	}

	// Tag of the request with the originatingObject to identify the reply
	requestToTwitter->setOriginatingObject(this);

	return requestToTwitter;
}

// Executing the request
void LibRT::Communicator::executeRequest() {
	// Preparing the request
	QNetworkRequest * request = prepareRequest();

	// Connection for receiving the response
	connect(&network, &QNetworkAccessManager::finished,
			this, &Communicator::endRequest);

	switch (requestType) {
		case GET:
			// GET request
			network.get(*request);
			break;

		case POST:
			// POST request
			network.post(*request, postParameters.getBuiltArgs().toLatin1());
			break;

		default:
			// Should not happen
			// TODO : error case
			break;
	}

	timeoutTimer.start();
}


///////////
// Slots //
///////////

// Treatments that have to be done at the end of the request
void LibRT::Communicator::endRequest(QNetworkReply * response) {
	// Treating the response

	// Is it the response of that precise request ?
	if (!response || this != response->request().originatingObject()) {
		// Null reply or bad sender -> No -> doing nothing
		return;
	}

	// That's our request. Let's do the treatments !

	// No timeout : stop the timer.
	timeoutTimer.stop();

	// Unwiring
	disconnect(&network, &QNetworkAccessManager::finished,
			   this, &Communicator::endRequest);

	// Extracting informations
	NetworkResponse netrep(response);
	response->deleteLater();

	/* responseBuffer (for debug purposes)
	qDebug() << "responseBuffer :" << '\n'
			 << netrep.getResponseBody() << '\n';
	//*/

	// Ending the request
	emit requestDone(netrep);
}

// Network timeout
void LibRT::Communicator::timeout() {
	// It seems that no response will arrive. That's enough ! Stop it !

	// Unwiring
	disconnect(&network, &QNetworkAccessManager::finished,
			   this, &Communicator::endRequest);

	NetworkResponse response(TIMEOUT_HTTP_CODE,
							 "timeout",
							 "",
							 "timeout",
							 serviceURL);

	// Ending the request
	emit requestDone(response);
}
