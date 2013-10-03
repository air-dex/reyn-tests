/// @file genericrequester.hpp
/// @brief Header of GenericRequester
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

#ifndef GENERICREQUESTER_HPP
#define GENERICREQUESTER_HPP

#include <QObject>
#include <QNetworkAccessManager>
#include <QUuid>
#include <QVariant>
#include "communicatormanager.hpp"
#include "../requestresult.hpp"
#include "../librt_global.hpp"
#include "../networkresult.hpp"
#include "../communicators/communicator.hpp"
#include "../communicators/getargs.hpp"
#include "../communicators/httpargs.hpp"

namespace LibRT {
	/// @class GenericRequester
	/// @brief Base class for all the requesters.
	class LIBRTSHARED_EXPORT GenericRequester : public QObject
	{
			Q_OBJECT

		public:
			/// @fn GenericRequester(LibRT::HTTPRequestType type,
			///						 QString url,
			///						 LibRT::NetworkResultType parseError = LibRT::JSON_PARSING,
			///						 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER,
			///						 QByteArray reqType = "application/x-www-form-urlencoded");
			/// @brief Constructor
			/// @param type Type of the request (GET ou POST).
			/// @param url URL called by the requester
			/// @param parseError Error type if an error occurs while parsing. Most
			/// of the time, this value is set to JSON_PARSING because results are
			/// written in JSON. However, OAuth requesters use their
			/// own parsing process so they need a special value called OAUTH_PARSING.
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			/// @param reqType Content Type for the request.
			GenericRequester(HTTPRequestType type,
							 QString url,
							 NetworkResultType parseError = JSON_PARSING,
							 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER,
							 QByteArray reqType = "application/x-www-form-urlencoded");

			/// @fn virtual ~GenericRequester();
			/// @brief Destructor.
			virtual ~GenericRequester();

			/// @fn QUuid getUuid();
			/// @brief Getter on the requester's UUID
			/// @return The requester's UUID
			QUuid getUuid();

			/// @fn virtual void executeRequest();
			/// @brief Executing the request. The method is virtual because of the
			/// Authorize step in the OAuth process whose request is quite different
			/// from the other ones.
			virtual void executeRequest();

		protected:
			/// @brief Entity managing communicators
			static CommunicatorManager communicatorManager;

			/// @brief UUID of the request
			QUuid uuid;

			/// @brief URL called by the requester
			QString requestURL;

			/// @brief Request type
			HTTPRequestType requestType;

			/// @brief Request content type
			QByteArray contentType;

			/// @brief Entity managing low level network tasks. It is a
			/// dependency injection aimed to be used as a network mock for
			/// tests. Most of the time it will be LibRT::LIBRT_NETWORK_MANAGER.
			QNetworkAccessManager & network;

			/// @fn virtual ArgsMap buildGETParameters();
			/// @brief Virtual method building GET Parameters
			/// @return GET parameters that will be passed to the Communicator.
			virtual ArgsMap buildGETParameters();

			/// @fn virtual GetArgs buildGETArgs();
			/// @brief Building the GET arguments builder.
			///
			/// The GenericRequester default builder build arguments like
			/// URL queries.
			/// @return GET parameters that will be passed to the Communicator.
			virtual GetArgs buildGETArgs();

			/// @fn virtual ArgsMap buildPOSTParameters();
			/// @brief Virtual method building POST Parameters
			/// @return POST parameters that will be passed to the Communicator.
			virtual ArgsMap buildPOSTParameters();

			/// @fn virtual HTTPArgs buildPOSTArgs();
			/// @brief Building the POST arguments builder.
			///
			/// The GenericRequester default builder build arguments like
			/// URL queries.
			/// @return POST parameters that will be passed to the Communicator.
			virtual HTTPArgs buildPOSTArgs();

			/// @fn virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
			///											ArgsMap postParameters);
			/// @brief Virtual method building headers
			/// @param getParameters GET parameters for the Communicator.
			/// @param postParameters POST parameters for the Communicator.
			/// @return HTTP headers that will be passed to the Communicator.
			virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
												ArgsMap postParameters);

			/// @brief Type of parsing error
			NetworkResultType parsingErrorType;

			/// @fn void setParsingErrorType(LibRT::NetworkResultType parseErrorType);
			/// @brief Setting parsingErrorType in classes which inherits from
			/// GenericRequesters.
			/// @param parseErrorType New value for parsingErrorType
			void setParsingErrorType(NetworkResultType parseErrorType);

			/////////////////////////////
			// Communicator management //
			/////////////////////////////

			/// @fn void removeCommunicator(Communicator * weblink);
			/// @brief Removing a requester of the Communicator manager
			/// @param weblink Communicator to remove
			void removeCommunicator(Communicator * weblink);

			/// @fn void executeNetworkRequest(HeadersMap headers,
			///								   GetArgs getParameters,
			///								   HTTPArgs postParameters);
			/// @brief Executing the low level request.
			/// @param headers HTTP headers
			/// @param getParameters GET arguments builder
			/// @param postParameters POST arguments builder
			void executeNetworkRequest(HeadersMap headers,
									   GetArgs getParameters,
									   HTTPArgs postParameters);


		//////////////////////////
		// Treatment of results //
		//////////////////////////

		public slots:
			/// @fn void treatResults(NetworkResponse netResponse);
			/// @brief Receiving the Communicator's results.
			/// @param netResponse Struct with response elements
			void treatResults(NetworkResponse netResponse);

		protected:
			/// @fn virtual void treatResults(NetworkResponse netResponse);
			/// @brief Treating the result, when the Twitter Communicator has
			/// just finished its work.
			/// @param netResponse Struct with response elements
			virtual void do_treatResults(NetworkResponse netResponse);

			/// @fn virtual QVariant parseResult(NetworkResponse results,
			///									 bool & parseOK,
			///									 QVariantMap & parsingErrors) = 0;
			/// @brief Method that will parse the raw results of the request.
			/// @param results Results to parse. Most of the time the method only
			/// uses the responseBody field.
			/// @param parseOK Boolean whose value will be set to true if there was
			/// no problem while parsing, false otherwise.
			/// @param parsingErrors QVariantMap that may contain information about
			/// errors that may occur while parsing.
			/// @return Parsed results
			virtual QVariant parseResult(NetworkResponse results,
										 bool & parseOK,
										 QVariantMap & parsingErrors) = 0;

			/// @fn virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
			///														NetworkResponse netResponse) = 0;
			/// @brief Treating parsed results
			/// @param parsedResults Parsed results to analyse in order to retrieve
			/// service errors.
			/// @param netResponse Other network response elements, if needed.
			/// @return The list of service errors
			virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
															NetworkResponse netResponse) = 0;

		signals:
			/// @fn void requestDone(RequestResult requestResult);
			/// @brief Signal sent when the results of the request received by
			/// the Twitter Communicator have been treated.
			/// @param requestResult Result of the request.
			void requestDone(RequestResult requestResult);
	};
}

#endif // GENERICREQUESTER_HPP
