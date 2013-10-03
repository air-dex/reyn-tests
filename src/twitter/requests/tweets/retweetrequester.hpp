/// @file retweetrequester.hpp
/// @brief Header of RetweetRequester
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

#ifndef RETWEETREQUESTER_HPP
#define RETWEETREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class RetweetRequester
	/// @brief Request consisting in retweeting a tweet
	/// @see https://dev.twitter.com/docs/api/1.1/post/statuses/retweet/%3Aid
	class RetweetRequester : public TwitterRequester
	{
			Q_OBJECT
		public:
			/// @fn RetweetRequester(TwitterAuthenticator & authManager,
			///						 qlonglong statusID,
			///						 bool userIDonly = false,
			///						 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param authManager Entities with OAuth values
			/// @param statusID ID of the tweet
			/// @param userIDonly Omit user details in the reply ?
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			RetweetRequester(const TwitterAuthenticator & authManager,
							 qlonglong statusID,
							 bool userIDonly = false,
							 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief ID of the tweet to favorite
			qlonglong tweetID;

			/// @brief Only include the userID in the "user" field of a tweet
			bool trimUser;

			/// @fn ArgsMap buildPOSTParameters();
			/// @brief Building postParameters
			ArgsMap buildPOSTParameters();
	};

}}

#endif // RETWEETREQUESTER_HPP
