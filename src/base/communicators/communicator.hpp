/// @file communicator.hpp
/// @brief Header of Communicator.
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

#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QUrl>
#include <QMap>
#include <QTimer>
#include "../headersmap.hpp"
#include "../httprequesttype.hpp"
#include "../networkresult.hpp"
#include "../librt_global.hpp"
#include "../utils/librtconstants.hpp"
#include "getargs.hpp"
#include "httpargs.hpp"

namespace LibRT {

	/// @class Communicator
	/// @brief Class managing communication with the Twitter API.
	///
	/// A Communicator needs the URL of the service, GET and POST arguments.
	/// It will doing the request and storing it in a QByteArray containing the
	/// response. <strong>The content of the QByteArray is not parsed.</strong>
	class LIBRTSHARED_EXPORT Communicator : public QObject
	{
		Q_OBJECT

		public:
			/// @fn Communicator(QString url,
			///					 LibRT::HTTPRequestType type,
			///					 HeadersMap headersParam = HeadersMap(),
			///					 GetArgs getArgs = GetArgs(),
			///					 HTTPArgs postArgs = HTTPArgs(),
			///					 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param url String representation of the URL
			/// @param type Type of the request (GET ou POST).
			/// @param headersParam HTTP headers
			/// @param getArgs GET arguments
			/// @param postArgs POST arguments
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			Communicator(QString url,
						 HTTPRequestType type,
						 HeadersMap headersParam = HeadersMap(),
						 GetArgs getArgs = GetArgs(),
						 HTTPArgs postArgs = HTTPArgs(),
						 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			/// @fn ~Communicator();
			/// @brief Destructor
			~Communicator();

			/// @fn QNetworkRequest * prepareRequest();
			/// @brief Preparing the request. It builds the parameters for GET
			/// and POST and the Authorization header if needed.
			/// @return A pointer on the request
			QNetworkRequest * prepareRequest();

			/// @fn virtual void executeRequest();
			/// @brief Executing the request
			virtual void executeRequest();


		signals:
			/// @fn void requestDone(NetworkResponse result);
			/// @brief Signal indicating the end of a request
			void requestDone(NetworkResponse result);


		protected slots:
			/// @fn void endRequest(QNetworkReply * response);
			/// @brief Slot called at the end of the request.
			/// @param response The network reply.
			void endRequest(QNetworkReply * response);

			/// @fn void timeout();
			/// @brief Slot called it there is a network timeout.
			void timeout();

		protected:
			/// @brief Timer to avoid to wait for responses ad vitam aeternam.
			QTimer timeoutTimer;

			// Entities for request

			/// @brief URL of the service
			QString serviceURL;

			/// @brief Request type
			HTTPRequestType requestType;

			/// @brief GET datas
			GetArgs getParameters;

			/// @brief POST datas
			HTTPArgs postParameters;

			/// @brief HTTP headers
			HeadersMap headers;

			/// @brief Entity managing low level network tasks. Most of the time
			/// it is a reference on LibRT::LIBRT_NETWORK_MANAGER but it
			/// may be another value just like a network mock for tests.
			QNetworkAccessManager & network;
	};
}

#endif // COMMUNICATOR_HPP
