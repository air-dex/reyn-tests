/// @file hometimelinerequester.hpp
/// @brief Header of HomeTimelineRequester
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

#ifndef HOMETIMELINEREQUESTER_HPP
#define HOMETIMELINEREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class HomeTimelineRequester
	/// @brief Request to retrieve the timeline withh all the users' friends' tweets
	/// @see https://dev.twitter.com/docs/api/1.1/get/statuses/home_timeline
	class HomeTimelineRequester : public TwitterRequester
	{
		Q_OBJECT

		public:
			/// @fn HomeTimelineRequester(const TwitterAuthenticator & authManager,
			///							  qlonglong oldestTweetID = Twitter::FAKE_TWEET_ID,
			///							  qlonglong youngestTweetID = Twitter::FAKE_TWEET_ID,
			///							  bool userIDonly = false,
			///							  bool withEntities = false,
			///							  bool withoutReplies = false,
			///							  int nbTweets = Twitter::DEFAULT_TWEETS_COUNT,
			///							  bool withContributorsDetails = false,
			///							  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param authManager Entity with authentication datas
			/// @param oldestTweetID Value of sinceID
			/// @param youngestTweetID Value of maxID
			/// @param userIDonly Value of trimUser
			/// @param withEntities Value of includeEntities
			/// @param withoutReplies Value of excludeReplies
			/// @param nbTweets Value of count
			/// @param withContributorsDetails Value of contributorsDetails
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			HomeTimelineRequester(const TwitterAuthenticator & authManager,
								  qlonglong oldestTweetID = Twitter::FAKE_TWEET_ID,
								  qlonglong youngestTweetID = Twitter::FAKE_TWEET_ID,
								  bool userIDonly = false,
								  bool withEntities = false,
								  bool withoutReplies = false,
								  int nbTweets = Twitter::DEFAULT_TWEETS_COUNT,
								  bool withContributorsDetails = false,
								  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief Number of tweets in the timeline. <strong>0 &lt; count &lt;
			/// Twitter::MAX_TWEETS_COUNT</strong>
			int count;

			/// @brief Minimum tweet ID allowed in the timeline
			qlonglong sinceID;

			/// @brief Maximum tweet ID allowed in the timeline
			qlonglong maxID;

			/// @brief Only include the userID in the "user" field of a tweet
			bool trimUser;

			/// @brief Including Tweet Entities in tweets
			bool includeEntities;

			/// @brief Prevent the return timeline from replies
			bool excludeReplies;

			/// @brief Including details about contributors
			bool contributorsDetails;

			/// @fn ArgsMap buildGETParameters();
			/// @brief Building getParameters
			ArgsMap buildGETParameters();
	};

}}

#endif // HOMETIMELINEREQUESTER_HPP
