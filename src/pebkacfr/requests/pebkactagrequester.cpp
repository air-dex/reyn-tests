/// @file pebkactagrequester.cpp
/// @brief Implementation of PebkacTagRequester
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

#include "pebkactagrequester.hpp"
#include "pebkacurls.hpp"
#include "patterngetargs.hpp"

using LibRT::ArgsMap;
using LibRT::GetArgs;
using PEBKAC::PatternGetArgs;
using PEBKAC::PebkacRequester;
using PEBKAC::PebkacAuthenticator;

// Constructor
PEBKAC::PebkacTagRequester::PebkacTagRequester(const PebkacAuthenticator &authPebkac,
											   QString uriTag,
											   int offset,
											   int limit,
											   QNetworkAccessManager &netManager) :
	PebkacRequester(GET, SHOW_PEBTAG_URL, authPebkac, netManager),
	tagURI(uriTag),
	offset(offset),
	limit(limit)
{}

// Building getParameters
ArgsMap PEBKAC::PebkacTagRequester::buildGETParameters() {
	ArgsMap getArgs = PebkacRequester::buildGETParameters();

	getArgs.insert("tag_uri", tagURI);
	pattern.append("/%3");

	if (offset != OFFSET_DEFAULT_VALUE && limit != LIMIT_DEFAULT_VALUE) {
		getArgs.insert("offset", QString::number(offset));
		getArgs.insert("limit", QString::number(limit));
		pattern.append("/%2,%1");
	}

	return getArgs;
}
