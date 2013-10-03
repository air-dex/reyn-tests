/// @file authorizerequester.hpp
/// @brief Header of AuthorizeRequester
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

#ifndef AUTHORIZEREQUESTER_HPP
#define AUTHORIZEREQUESTER_HPP

#include "oauthrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class AuthorizeRequester
	/// @brief Requester for OAuth authentication
	class AuthorizeRequester : public OAuthRequester
	{
		Q_OBJECT

		public:
			/// @fn AuthorizeRequester(const TwitterAuthenticator & authManager,
			///						   bool forceLog = false,
			///						   QString writeLogin = Twitter::FAKE_SCREEN_NAME,
			///						   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param authManager Informations for OAuth.
			/// @param forceLog Value for forceLogin
			/// @param writeLogin Value for screenName
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			AuthorizeRequester(const TwitterAuthenticator & authManager,
							   bool forceLog = false,
							   QString writeLogin = Twitter::FAKE_SCREEN_NAME,
							   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief Boolean indicating if the user as to sign in to
			/// Twitter to authorize the application. Quite useless in Reyn Tweets.
			bool forceLogin;

			/// @brief Screen name of the user which want to authorize the app,
			/// in order to write it in the authentication page which will be
			/// returned. Quite useless in Reyn Tweets.
			QString screenName;

			/////////////////////////////////
			// Override for this requester //
			/////////////////////////////////

			/// @fn ArgsMap buildGETParameters();
			/// @brief Method building GET Parameters
			ArgsMap buildGETParameters();

			/// @fn QVariant parseResult(NetworkResponse results,
			///							 bool & parseOK,
			///							 QVariantMap & parsingErrors);
			/// @brief Method that will parse the raw results of the request.
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

			/// @fn virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
			///														NetworkResponse netResponse);
			/// @brief Treating parsed results
			///
			/// It is overriden because of XML results if there were errors.
			/// @param parsedResults Parsed results to analyse in order to retrieve
			/// service errors.
			/// @param netResponse Other network responce elements, if needed.
			/// @return The list of service errors
			/// @see https://dev.twitter.com/docs/error-codes-responses
			virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
															NetworkResponse netResponse);
	};

}}

#endif // AUTHORIZEREQUESTER_HPP
