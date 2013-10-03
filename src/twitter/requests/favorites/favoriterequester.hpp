/// @file favoriterequester.hpp
/// @brief Header of FavoriteRequester
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

#ifndef FAVORITEREQUESTER_HPP
#define FAVORITEREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class FavoriteRequester
	/// @brief Requester to favorite a tweet
	/// @see https://dev.twitter.com/docs/api/1.1/post/favorites/create (favorite)
	/// @see https://dev.twitter.com/docs/api/1.1/post/favorites/destroy (unfavorite)
	class FavoriteRequester : public TwitterRequester
	{
		Q_OBJECT

		public:
			/// @fn FavoriteRequester(const TwitterAuthenticator & authManager,
			///						  bool favorited,
			///						  qlonglong id,
			///						  bool withEntities = false,
			///						  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor with a screen name.
			/// @param authManager Entity with authentication datas
			/// @param favorited Boolean whose value indicates whether the tweet is favorited
			/// (true) or not (false).
			/// @param id ID of the tweet to favorite
			/// @param withEntities Value of includeEntities
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			FavoriteRequester(const TwitterAuthenticator & authManager,
							  bool favorited,
							  qlonglong id,
							  bool withEntities = false,
							  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief Boolean whose value indicates whether the tweet is favorited
			/// (true) or not (false).
			bool isFavorited;

			/// @brief ID of the tweet to favorite
			qlonglong tweetID;

			/// @brief Include Tweet Entities of the tweet in the reply ?
			bool includeEntities;

			/// @fn void buildPOSTParameters();
			/// @brief Building postParameters
			ArgsMap buildPOSTParameters();
	};

}}

#endif // FAVORITEREQUESTER_HPP