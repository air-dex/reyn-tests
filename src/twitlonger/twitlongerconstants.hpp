/// @file twitlongerconstants.hpp
/// @brief Implementation for Reyn Tweets constants related to TwitLonger.
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

#ifndef TWITLONGERCONSTANTS_HPP
#define TWITLONGERCONSTANTS_HPP

#include <QString>
#include "../base/librt_global.hpp"

namespace LibRT {
	/// @namespace TwitLonger
	/// @brief Namespace containing all the TwitLonger API URLs.
	namespace TwitLonger {
		/// @brief Constant for a fake Tweet ID
		extern const qlonglong LIBRTSHARED_EXPORT FAKE_TWEET_ID;

		/// @brief Fake TwitLonger message ID
		extern const QString LIBRTSHARED_EXPORT FAKE_MESSAGE_ID;

		/// @brief Constant for a fake Twitter screen name (empty string)
		extern const QString LIBRTSHARED_EXPORT FAKE_SCREEN_NAME;
	}
}

#endif // TWITLONGERCONSTANTS_HPP
