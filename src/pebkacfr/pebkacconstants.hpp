/// @file pebkacconstants.hpp
/// @brief Header with constants for PEBKAC.fr on LibRT
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

#ifndef PEBKACCONSTANTS_HPP
#define PEBKACCONSTANTS_HPP

#include <QString>
#include "../base/librt_global.hpp"

namespace LibRT {
	/// @namespace Pebkac
	/// @brief General namespace for stuff related to the PEBKAC.fr API in LibRT.
	namespace Pebkac {
		/// @brief Default value for offsets in PEBKAC lists requests.
		extern const int LIBRTSHARED_EXPORT OFFSET_DEFAULT_VALUE;

		/// @brief Default value for limits in PEBKAC lists requests.
		extern const int LIBRTSHARED_EXPORT LIMIT_DEFAULT_VALUE;

		/// @brief Maximum value for limits in PEBKAC lists requests.
		extern const int LIBRTSHARED_EXPORT LIMIT_MAX_VALUE;

		/// @brief Default value for periods used to retrieve PEBKACs.
		extern const QString LIBRTSHARED_EXPORT PEBKAC_DEFAULT_PERIOD;

		/// @brief Fake value for PEBKAC.fr user IDs.
		extern const int LIBRTSHARED_EXPORT FAKE_USER_ID;

		/// @brief User ID for PEBKAC.fr unregistered users.
		extern const int LIBRTSHARED_EXPORT UNREGESITERED_USER_ID;

		/// @brief Fake value for PEBKAC IDs.
		extern const int LIBRTSHARED_EXPORT FAKE_PEBKAC_ID;

		/// @brief Fake name for PEBKAC.fr user IDs.
		extern const QString LIBRTSHARED_EXPORT FAKE_USER_NAME;

		/// @brief Fake value for PEBKAC tags.
		extern const QString LIBRTSHARED_EXPORT FAKE_TAG;
	}
}

/// @namespace PEBKAC
/// @brief Shortcut for LibRT::Pebkac
namespace PEBKAC = LibRT::Pebkac;

#endif // PEBKACCONSTANTS_HPP
