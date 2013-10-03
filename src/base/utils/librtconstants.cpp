/// @file librtconstants.cpp
/// @brief Implementation for libRT constants.
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

#include "librtconstants.hpp"

// Network manager
#ifdef Q_OS_WIN
	QNetworkAccessManager LibRT::LIBRT_NETWORK_MANAGER = QNetworkAccessManager();
#elif defined(Q_OS_LINUX)
	QNetworkAccessManager LibRT::LIBRT_NETWORK_MANAGER;
#endif

// Fake tweet ID
const qlonglong LibRT::FAKE_ID = -1;

// Generic fake value for ID represented by a string (empty string)
const QString LibRT::FAKE_STRING_ID = "";

// Fake longitude
const float LibRT::FAKE_LONGITUDE = 181;

// Fake latitude
const float LibRT::FAKE_LATITUDE = 91;

// Maximum longitude
const float LibRT::MAX_LONGITUDE = 180;

// Maximum latitude
const float LibRT::MAX_LATITUDE = 90;

// Fake value for a token (empty string)
const QByteArray LibRT::FAKE_TOKEN = "";

// Fake value for an URL (empty string)
const QString LibRT::FAKE_URL = "";