/// @file pebkacurls.cpp
/// @brief Implementation of the "Pekbac" namespace part containing
/// Pekbac.fr URLs.
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

#include "pebkacurls.hpp"

namespace PEBKAC = LibRT::Pebkac;

// Retrieving the latst PEBKACs.
QString PEBKAC::LATEST_PEBKACS_URL = QString::fromUtf8("http://api.pebkac.fr/latest");

// Retrieving the best PEBKACs.
QString PEBKAC::TOP_PEBKACS_URL = QString::fromUtf8("http://api.pebkac.fr/top");

// Retrieving the worst PEBKACs.
QString PEBKAC::FLOP_PEBKACS_URL = QString::fromUtf8("http://api.pebkac.fr/flop");

// Getting random PEBKACs
QString PEBKAC::RANDOM_PEBKACS_URL = QString::fromUtf8("http://api.pebkac.fr/random");

// Showing the list of PEBKAC.fr members.
QString PEBKAC::SHOW_PEBKACFR_USERS_URL = QString::fromUtf8("http://api.pebkac.fr/userlist");

// Showing PEBKACs of a given PEBKAC.fr member.
QString PEBKAC::SHOW_USER_PEBKACS_URL = QString::fromUtf8("http://api.pebkac.fr/user");

// Showing all the tags used for PEBKACs
QString PEBKAC::SHOW_TAGS_URL = QString::fromUtf8("http://api.pebkac.fr/taglist");

// Showing PEBKACs related to a tag.
QString PEBKAC::SHOW_PEBTAG_URL = QString::fromUtf8("http://api.pebkac.fr/tag");

// Retrieving a given PEBKAC.
QString PEBKAC::SHOW_PEBKAC_URL = QString::fromUtf8("http://api.pebkac.fr/pebkac");

// Retrieving the comments of a given PEBKAC.
QString PEBKAC::SHOW_PEBKAC_COMMENTS_URL = QString::fromUtf8("http://api.pebkac.fr/pebkacComments");
