/// @file verifycredentialsrequester.hpp
/// @brief Header of VerifyCredentialsRequester
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

#ifndef VERIFYCREDENTIALSREQUESTER_HPP
#define VERIFYCREDENTIALSREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class VerifyCredentialsRequester
	/// @brief Request to verify if the access tokens owned by Reyn Tweets
	/// to use a given Twitter account are the right ones.
	/// @see https://api.twitter.com/1.1/account/verify_credentials.json
	class VerifyCredentialsRequester : public TwitterRequester
	{
			Q_OBJECT
		public:
			/// @fn VerifyCredentialsRequester(const TwitterAuthenticator & authManager,
			///								   bool entities = false,
			///								   bool skipLastTweet = false,
			///								   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER
			/// @brief Constructor
			/// @param authManager Twitter Authenticator for authentication
			/// @param entities Include entities in the last tweet of the user ?
			/// @param skipLastTweet Skip last tweet written by the user ?
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			VerifyCredentialsRequester(const TwitterAuthenticator & authManager,
									   bool entities = false,
									   bool skipLastTweet = false,
									   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			////////////////
			// Parameters //
			////////////////

			/// @brief Boolean indicating if entities of a tweet have to be included
			/// in the reply
			bool includeEntities;

			/// @brief When this value is set to true, the last tweet of the user
			/// is not included.
			bool skipStatus;

			/// @fn ArgsMap buildGETParameters();
			/// @brief Building getParameters
			ArgsMap buildGETParameters();
	};

}}

#endif // VERIFYCREDENTIALSREQUESTER_HPP
