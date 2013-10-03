/// @file pebkacconstants.cpp
/// @brief Header of PebkacfrUserRequester
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

#include "pebkacconstants.hpp"

#include "../base/utils/librtconstants.hpp"

// Default value for offsets in PEBKAC lists requests.
const int PEBKAC::OFFSET_DEFAULT_VALUE = 0;

// Default value for limits in PEBKAC lists requests.
const int PEBKAC::LIMIT_DEFAULT_VALUE = 10;

// Maximum value for limits in PEBKAC lists requests.
const int PEBKAC::LIMIT_MAX_VALUE = 50;

// Default value for periods used to retrieve PEBKACs.
const QString PEBKAC::PEBKAC_DEFAULT_PERIOD = "";

// Fake value for PEBKAC.fr user IDs.
const int PEBKAC::FAKE_USER_ID = LibRT::FAKE_ID;

// User ID for PEBKAC.fr unregistered users.
const int PEBKAC::UNREGESITERED_USER_ID = 0;

// Fake value for PEBKAC IDs.
const int PEBKAC::FAKE_PEBKAC_ID = LibRT::FAKE_ID;

// Fake name for PEBKAC.fr user IDs.
const QString PEBKAC::FAKE_USER_NAME = LibRT::FAKE_STRING_ID;

// Fake value for PEBKAC tags.
const QString PEBKAC::FAKE_TAG = LibRT::FAKE_STRING_ID;
