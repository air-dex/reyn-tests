/// @file pebkacperiod.hpp
/// @brief Header of PebkacPeriod and convertions between this enum and QString.
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

#ifndef PEBKACPERIOD_HPP
#define PEBKACPERIOD_HPP

#include "../base/librt_global.hpp"
#include "../base/utils/librtconstants.hpp"

// NOTE : keep for library clients instead of LibRT ?

namespace LibRT {
	namespace Pebkac {
		/// @enum LIBRTSHARED_EXPORT PebkacPeriod
		/// @brief Period of time to retrieve PEBKAC
		enum LIBRTSHARED_EXPORT PebkacPeriod {
			/// @brief Invalid value for the enum.
			INVALID_PERIOD,

			/// @brief Pebkacs of last month
			MONTH,

			/// @brief Pebkacs of last week
			WEEK,

			/// @brief All the PEBKACs !
			ALL
		};

		/// @fn LIBRTSHARED_EXPORT QString pebkacPeriodToString(PebkacPeriod period);
		/// @brief Converting a PebkacPeriod into a QString.
		/// @param period Pebkac period under a PebkacPeriod form.
		/// @return Pebkac period under a QString form.
		LIBRTSHARED_EXPORT QString pebkacPeriodToString(PebkacPeriod period);

		/// @fn LIBRTSHARED_EXPORT PebkacPeriod stringToPebkacPeriod(QString periodStr);
		/// @brief Converting a QString into a PebkacPeriod.
		/// @param periodStr Pebkac period under a QString form.
		/// @return Pebkac period under a PebkacPeriod form.
		LIBRTSHARED_EXPORT PebkacPeriod stringToPebkacPeriod(QString periodStr);
	}
}

#endif // PEBKACPERIOD_HPP
