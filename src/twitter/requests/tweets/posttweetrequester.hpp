/// @file posttweetrequester.hpp
/// @brief Header of PostTweetRequester
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

#ifndef POSTTWEETREQUESTER_HPP
#define POSTTWEETREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class PostTweetRequester
	/// @brief Requester for posting a tweet without media
	/// @see https://dev.twitter.com/docs/api/1.1/post/statuses/update
	class PostTweetRequester : public TwitterRequester
	{
		Q_OBJECT

		public:
			/// @fn PostTweetRequester(const TwitterAuthenticator & authManager,
			///						   QString status,
			///						   qlonglong replyTostatusID = Twitter::FAKE_TWEET_ID,
			///						   float lat = LibRT::FAKE_LATITUDE,
			///						   float lon = LibRT::FAKE_LONGITUDE,
			///						   QString place = Twitter::FAKE_PLACE_ID,
			///						   bool showCoord = false,
			///						   bool userIDonly = true,
			///						   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Posting a tweet without media
			/// @param authManager TwitterAuthenticator with authentication infos
			/// @param status Text of the tweet
			/// @param replyTostatusID If the tweet is a reply, this parameter is
			/// the ID of the tweet that this tweet replies to.
			/// @param lat For geolocation, your longitude.
			/// @param lon For geolocation, your latitude.
			/// @param place For geolocation, ID of the place where the tweet
			/// is supposed to be sent
			/// @param showCoord Displaying the coordonates of the tweet
			/// with a pin on a map
			/// @param userIDonly In tweets, giving only the ID of the author (true).
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			PostTweetRequester(const TwitterAuthenticator & authManager,
							   QString status,
							   qlonglong replyTostatusID = Twitter::FAKE_TWEET_ID,
							   float lat = LibRT::FAKE_LATITUDE,
							   float lon = LibRT::FAKE_LONGITUDE,
							   QString place = Twitter::FAKE_PLACE_ID,
							   bool showCoord = false,
							   bool userIDonly = true,
							   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);


		protected:
			/// @brief Text to post
			QString tweet;

			/// @brief ID of the tweet that this status replies to
			qlonglong replyToTweetID;

			/// @brief Only include the userID in the "user" field of a tweet
			bool trimUser;

			/// @brief Longitude of the tweet
			float longitude;

			/// @brief Latitude of the tweet
			float latitude;

			/// @brief place where the tweet was supposed to be sent
			QString reversePlace;

			/// @brief Displaying coordonates on a map
			bool displayCoord;

			/// @fn ArgsMap buildPOSTParameters();
			/// @brief Building postParameters
			ArgsMap buildPOSTParameters();
	};

}}

#endif // POSTTWEETREQUESTER_HPP
