/// @file twitlongerconstants.cpp
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

#include "twitlongerconstants.hpp"

#include "../base/utils/librtconstants.hpp"

// Fake tweet ID
const qlonglong LibRT::TwitLonger::FAKE_TWEET_ID = LibRT::FAKE_ID;

// Fake TwitLonger message ID
const QString LibRT::TwitLonger::FAKE_MESSAGE_ID = LibRT::FAKE_STRING_ID;

// Fake Twitter screen name (empty string)
const QString LibRT::TwitLonger::FAKE_SCREEN_NAME = LibRT::FAKE_STRING_ID;