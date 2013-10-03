/// @file genericcalls.hpp
/// @brief Header of GenericCalls
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2012, 2013 Romain Ducher
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

#ifndef GENERICCALLS_HPP
#define GENERICCALLS_HPP

#include <QObject>
#include "../librt_global.hpp"
#include "../requests/genericrequester.hpp"
#include "../resultwrapper.hpp"
#include "../utils/librtconstants.hpp"
#include "requestermanager.hpp"

namespace LibRT {
	/// @class GenericCalls
	/// @brief Base class for all classes which manage calls to services.
	///
	/// It contains the methods for the core management of the calls so its derived
	/// class can focused on the methods calling a service and not the core management.
	class LIBRTSHARED_EXPORT GenericCalls : public QObject
	{
		Q_OBJECT

		//////////////////////////////////
		// Core management of the class //
		//////////////////////////////////

		public:
			/// @fn GenericCalls(QObject * requester,
			///					 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param requester Entity asking for the request
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			GenericCalls(QObject * requester,
						 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			/// @fn ~GenericCalls();
			/// @brief Destructor
			~GenericCalls();

		signals:
			/// @fn void sendResult(ResultWrapper res);
			/// @brief Signal emitted to the QObject that sends the request
			/// @param res Result of a request
			void sendResult(ResultWrapper res);

		public slots:
			/// @fn void endRequest(RequestResult requestResult);
			/// @brief Slot executed when a requester has finished its work
			/// @param requestResult Result of the request.
			void endRequest(RequestResult requestResult);

		protected:
			/// @brief QObject that asks for the request
			QObject * requestDemander;

			/// @brief Entity managing low level network tasks. It is a
			/// dependency injection aimed to be used as a network mock for
			/// tests. Most of the time it will be LibRT::LIBRT_NETWORK_MANAGER.
			QNetworkAccessManager & network;

			/// @brief Entity which manages requests that are running
			static RequesterManager requesterManager;

			///////////////////////////
			// Requesters management //
			///////////////////////////

			/// @fn void addRequester(GenericRequester * requester);
			/// @brief Adding a requester to the requester manager
			/// @param requester Address of the requester
			void addRequester(GenericRequester * requester);

			/// @fn void removeRequester(GenericRequester * requester);
			/// @brief Removing a requester of the requester manager
			/// @param requester Address of the requester
			void removeRequester(GenericRequester * requester);

			/// @fn void executeRequest(GenericRequester * requester);
			/// @brief Inline method for executing requests
			/// @param requester The requester
			void executeRequest(GenericRequester * requester);
	};
}

#endif // GENERICCALLS_HPP
