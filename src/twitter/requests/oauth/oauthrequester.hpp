/// @file oauthrequester.hpp
/// @brief Header of OAuthRequester
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

#ifndef OAUTHREQUESTER_HPP
#define OAUTHREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @brief Input name of the button to cancel the authorize process
	extern QString DENY_NAME;

	/// @class OAuthRequester
	/// @brief Generic requester for requests dealing with OAuth
	class OAuthRequester : public TwitterRequester
	{
		Q_OBJECT

		public:
			/// @fn OAuthRequester(LibRT::HTTPRequestType type,
			///					   QString url,
			///					   const TwitterAuthenticator & authManager,
			///					   ErrorType parseErrorType,
			///					   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER,
			///					   bool tokenNeeded = true,
			///					   bool callbackURLNeeded = false,
			///					   bool verifierNeeded = false);
			/// @brief Constructor
			/// @param type Type of the request (GET ou POST).
			/// @param url URL of the request
			/// @param authManager Information for OAuth. The requester takes its
			/// memory address.
			/// @param parseErrorType Error type while parsing. It is not JSON.
			/// @param tokenNeeded Boolean indicating if the oauth_token parameter
			/// is required for authentication.
			/// @param callbackURLNeeded Boolean indicating if the oauth_callback
			/// parameter is required for authentication.
			/// @param verifierNeeded Boolean indicating if the oauth_verifier
			/// parameter is required for authentication.
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			OAuthRequester(HTTPRequestType type,
						   QString url,
						   const TwitterAuthenticator & authManager,
						   NetworkResultType parseErrorType,
						   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER,
						   bool tokenNeeded = true,
						   bool callbackURLNeeded = false,
						   bool verifierNeeded = false);

		protected:
			/// @brief Boolean indicating if the oauth_token parameter is required
			/// for authentication.
			bool oauthTokenNeeded;

			/// @brief Boolean indicating if the oauth_callback parameter
			/// is required for authentication.
			bool oauthCallbackUrlNeeded;

			/// @brief Boolean indicating if the oauth_token parameter is required
			/// for authentication.
			bool oauthVerifierNeeded;

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

#endif // OAUTHREQUESTER_HPP
