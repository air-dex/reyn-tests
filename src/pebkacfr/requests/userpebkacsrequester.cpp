/// @file userpebkacsrequester.cpp
/// @brief Implementation of UserPebkacsRequester
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

#include "userpebkacsrequester.hpp"
#include "pebkacurls.hpp"

using LibRT::ArgsMap;
using PEBKAC::PebkacRequester;
using PEBKAC::PebkacAuthenticator;

// Constructor
PEBKAC::UserPebkacsRequester::UserPebkacsRequester(const PebkacAuthenticator & authPebkac,
												   int idUser,
												   int offset,
												   int limit,
												   QNetworkAccessManager & netManager) :
	PebkacRequester(GET, SHOW_USER_PEBKACS_URL, authPebkac, netManager),
	userID(idUser),
	offset(offset),
	limit(limit)
{}

// Building getParameters
ArgsMap PEBKAC::UserPebkacsRequester::buildGETParameters() {
	ArgsMap getArgs = PebkacRequester::buildGETParameters();

	getArgs.insert("user_id", QString::number(userID));
	pattern.append("/%3");

	if (offset != OFFSET_DEFAULT_VALUE && limit != LIMIT_DEFAULT_VALUE) {
		getArgs.insert("offset", QString::number(offset));
		getArgs.insert("limit", QString::number(limit));
		pattern.append("/%2,%1");
	}

	return getArgs;
}
