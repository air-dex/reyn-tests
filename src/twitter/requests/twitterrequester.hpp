/// @file twitterrequester.hpp
/// @brief Header of TwitterRequester
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

#ifndef TWITTERREQUESTER_HPP
#define TWITTERREQUESTER_HPP

#include "../../base/requests/genericrequester.hpp"
#include "twitterurls.hpp"
#include "../twitterauthenticator.hpp"
#include "../twitterconstants.hpp"

namespace LibRT { namespace Twitter {

	/// @class TwitterRequester
	/// @brief Base class for requesters that use the Twitter API.
	///
	/// With the v1.1 Twitter API, all the requests have to be authenticated. As a
	/// consequence, this class is merged with its daughter AuthenticationRequester.
	class TwitterRequester : public GenericRequester
	{
		Q_OBJECT

		public:
			/// @fn TwitterRequester(LibRT::HTTPRequestType type,
			///						 QString url,
			///						 const TwitterAuthenticator & authManager,
			///						 QNetworkAccessManager & netManager = LibRT::LIBRT_NETWORK_MANAGER,
			///						 LibRT::NetworkResultType parseError = LibRT::JSON_PARSING);
			/// @brief Constructor
			/// @param type Type of the request (GET ou POST).
			/// @param url URL called by the requester.
			/// @param authManager Entity with information for authentication.
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			/// @param parseError Error type if an error occurs while parsing.
			/// Most of the time the Twitter API sends back JSON results (except
			/// for OAuth) so LibRT::JSON_PARSING is set as a default value for
			/// this parameter.
			TwitterRequester(HTTPRequestType type,
							 QString url,
							 const TwitterAuthenticator & authManager,
							 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER,
							 NetworkResultType parseError = JSON_PARSING);

		protected:
			/// @brief Entity with authentication information
			const TwitterAuthenticator & oauthManager;


			////////////////////////////
			// Network reply tratment //
			////////////////////////////

			/// @fn virtual QVariant parseResult(NetworkResponse results,
			///									 bool & parseOK,
			///									 QVariantMap & parsingErrors);
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
										 QVariantMap & parsingErrors);

			/// @fn virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
			///														NetworkResponse netResponse);
			/// @brief Treating parsed results
			/// @param parsedResults Parsed results to analyse in order to retrieve
			/// service errors.
			/// @param netResponse Other network responce elements, if needed.
			/// @return The list of service errors
			/// @see https://dev.twitter.com/docs/error-codes-responses
			virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
															NetworkResponse netResponse);


			///////////////////////////
			// Building HTTP Headers //
			///////////////////////////

			/// @fn virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
			///											ArgsMap postParameters);
			/// @brief Building Content-Type and Authorize headers
			/// @param getParameters GET parameters for the Communicator.
			/// @param postParameters POST parameters for the Communicator.
			/// @return The HTTP headers for the Communicator
			virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters, ArgsMap postParameters);

			/// @fn virtual QByteArray getAuthorizationHeader(ArgsMap getParameters,
			///												  ArgsMap postParameters);
			/// @brief Building the "Authorization" header needed for Twitter requests
			///
			/// This method is virtual since it is oveeriden for OAuth requesters.
			/// @param getParameters GET parameters for the Communicator.
			/// @param postParameters POST parameters for the Communicator.
			/// @return "Authorization" header for the Twitter API.
			/// @see https://dev.twitter.com/docs/auth/authorizing-request
			virtual QByteArray getAuthorizationHeader(ArgsMap getParameters,
													  ArgsMap postParameters);
	};

}}

#endif // TWITTERREQUESTER_HPP
