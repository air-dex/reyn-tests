/// @file accesstokenrequester.hpp
/// @brief Header of AccessTokenRequester
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

#ifndef ACCESSTOKENREQUESTER_HPP
#define ACCESSTOKENREQUESTER_HPP

#include "oauthrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class AccessTokenRequester
	/// @brief Requester for getting OAuth access tokens
	/// @see https://dev.twitter.com/docs/api/1/post/oauth/access_token
	class AccessTokenRequester : public OAuthRequester
	{
		Q_OBJECT

		public:
			/// @fn AccessTokenRequester(const TwitterAuthenticator & authManager,
			///							 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param authManager Information for OAuth.
			/// @param verifier The OAuth Verifier needed for getting Access tokens.
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			AccessTokenRequester(const TwitterAuthenticator & authManager,
								 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @fn ArgsMap buildPOSTParameters();
			/// @brief Method building POST Parameters
			ArgsMap buildPOSTParameters();

			/// @fn QVariant parseResult(NetworkResponse results,
			///							 bool & parseOK,
			///							 QVariantMap & parsingErrors);
			/// @brief Method that will parse the raw results of the request.
			///
			/// For this kind of request, results look like :<br/><code>
			/// oauth_token=value of the access token&
			/// oauth_token_secret=value of the token secret&
			/// user_id=id of the user&
			/// screen_name=screen name
			/// </code><br/>
			/// <strong>Warning : tokens value are not encrypted in the parsed
			/// map that contains results.</strong>
			/// @param results Results to parse. Most of the time the method only
			/// uses the responseBody field.
			/// @param parseOK Boolean whose value will be set to true if there was
			/// no problem while parsing, false otherwise.
			/// @param parsingErrors QVariantMap that may contain information about
			/// errors that may occur while parsing.
			/// @return Parsed results
			QVariant parseResult(NetworkResponse results,
								 bool & parseOK,
								 QVariantMap & parsingErrors);
	};

}}

#endif // ACCESSTOKENREQUESTER_HPP