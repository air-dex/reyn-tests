/// @file librtconstants.hpp
/// @brief Header for libRT constants.
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

#ifndef LIBRTCONSTANTS_HPP
#define LIBRTCONSTANTS_HPP

#include <QString>
#include <QNetworkAccessManager>
#include "../librt_global.hpp"

namespace LibRT {
	/////////////////////
	// Network Manager //
	/////////////////////

	/// @brief Network manager used by all the requesters for all the request.
	/// <strong>Including him directly in the Communicator
	/// <a href="https://code.google.com/p/reyn-tweets/issues/detail?id=36">
	/// could cause crashes</a></strong>.
	extern QNetworkAccessManager LIBRTSHARED_EXPORT LIBRT_NETWORK_MANAGER;


	///////////////
	// Constants //
	///////////////

	/// @brief Generic fake ID.
	extern const qlonglong LIBRTSHARED_EXPORT FAKE_ID;

	/// @brief Generic fake value for ID represented by a string (empty string)
	extern const QString LIBRTSHARED_EXPORT FAKE_STRING_ID;

	/// @brief Fake longitude
	extern const float LIBRTSHARED_EXPORT FAKE_LONGITUDE;

	/// @brief Fake latitude
	extern const float LIBRTSHARED_EXPORT FAKE_LATITUDE;

	/// @brief Maximum absolute value for a longitude (180 since a valid
	/// longitude is between -180 and +180).
	extern const float LIBRTSHARED_EXPORT MAX_LONGITUDE;

	/// @brief Maximum absolute value for a latitude (180 since a valid
	/// latitude is between -90 and +90).
	extern const float LIBRTSHARED_EXPORT MAX_LATITUDE;

	/// @brief Fake value for a token (empty string)
	extern const QByteArray LIBRTSHARED_EXPORT FAKE_TOKEN;

	/// @brief Fake value for an URL (empty string)
	extern const QString LIBRTSHARED_EXPORT FAKE_URL;
}

#endif // LIBRTCONSTANTS_HPP
