/// @file twitterconstants.hpp
/// @brief Header for Reyn Tweets constants related to Twitter.
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2013 Romain Ducher
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

#ifndef TWITTERCONSTANTS_HPP
#define TWITTERCONSTANTS_HPP

#include <QString>
#include <QList>
#include "../base/utils/httpcode.hpp"
#include "../base/librt_global.hpp"

namespace LibRT {

	/// @namespace Twitter
	/// @brief Namespace containing all the Twitter API URLs.
	namespace Twitter {
		/// @brief Constant for a fake Tweet ID (-1)
		extern const qlonglong LIBRTSHARED_EXPORT FAKE_TWEET_ID;

		/// @brief Constant for a fake Tweet ID (-1)
		extern const qlonglong LIBRTSHARED_EXPORT FAKE_USER_ID;

		/// @brief Default number of tweets retrieved per call (20).
		extern const int LIBRTSHARED_EXPORT DEFAULT_TWEETS_COUNT;

		/// @brief Maximum number of tweets that can be retrieved per call (200).
		extern const int LIBRTSHARED_EXPORT MAX_TWEETS_COUNT;

		/// @brief Constant for a fake Twitter screen name (empty string)
		extern const QString LIBRTSHARED_EXPORT FAKE_SCREEN_NAME;

		/// @brief Fake Twitter place ID
		extern const QString LIBRTSHARED_EXPORT FAKE_PLACE_ID;

		/// @brief Twitter API error codes
		/// @see https://dev.twitter.com/docs/error-codes-responses
		extern const QList<HTTPCode> LIBRTSHARED_EXPORT TWITTER_ERROR_CODES;

		/// @fn const QList<LibRT::HTTPCode> initTwitterErrorCodes();
		/// @brief Inits TWITTER_ERROR_CODES
		/// @return The TWITTER_ERROR_CODES value
		const QList<HTTPCode> LIBRTSHARED_EXPORT initTwitterErrorCodes();
	}
}

#endif // TWITTERCONSTANTS_HPP
