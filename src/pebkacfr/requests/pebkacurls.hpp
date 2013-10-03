/// @file pebkacurls.hpp
/// @brief Header of the "Pekbac" namespace part containing Pekbac.fr URLs.
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

#ifndef PEBKACURLS_HPP
#define PEBKACURLS_HPP

#include <QString>

namespace LibRT {
	namespace Pebkac {
		/// @brief URL for retrieving the latst PEBKACs.
		extern QString LATEST_PEBKACS_URL;

		/// @brief URL for retrieving the best PEBKACs.
		extern QString TOP_PEBKACS_URL;

		/// @brief URL for retrieving the worst PEBKACs.
		extern QString FLOP_PEBKACS_URL;

		/// @brief URL for getting random PEBKACs
		extern QString RANDOM_PEBKACS_URL;

		/// @brief URL for showing the list of PEBKAC.fr members.
		extern QString SHOW_PEBKACFR_USERS_URL;

		/// @brief URL for showing PEBKACs of a given PEBKAC.fr member.
		extern QString SHOW_USER_PEBKACS_URL;

		/// @brief URL for showing all the tags used for PEBKACs
		extern QString SHOW_TAGS_URL;

		/// @brief URL for showing PEBKACs related to a tag.
		extern QString SHOW_PEBTAG_URL;

		/// @brief URL for retrieving a given PEBKAC.
		extern QString SHOW_PEBKAC_URL;

		/// @brief URL for retrieving the comments of a given PEBKAC.
		extern QString SHOW_PEBKAC_COMMENTS_URL;
	}
}

#endif // PEBKACURLS_HPP
