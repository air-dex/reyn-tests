/// @file pebkacperiod.cpp
/// @brief Implementation of convertions between PebkacPeriod and QString.
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

#include "pebkacperiod.hpp"
#include "pebkacconstants.hpp"

// PebkacPeriod to QString
QString PEBKAC::pebkacPeriodToString(PEBKAC::PebkacPeriod period) {
	switch (period) {
		case MONTH:
			return "month";

		case WEEK:
			return "week";

		case ALL:
			return "";

		default:
			return "null";
	}
}

// QString to a PebkacPeriod
PEBKAC::PebkacPeriod PEBKAC::stringToPebkacPeriod(QString periodStr) {
	if (periodStr == "") {
		return ALL;
	} else if (periodStr == "month") {
		return MONTH;
	} else if (periodStr == "week") {
		return WEEK;
	} else {
		return INVALID_PERIOD;
	}
}
