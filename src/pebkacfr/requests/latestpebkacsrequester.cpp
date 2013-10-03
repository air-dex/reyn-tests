/// @file latestpebkacsrequester.cpp
/// @brief Implementation of LatestPebkacsRequester
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

#include "latestpebkacsrequester.hpp"
#include "pebkacurls.hpp"

using LibRT::ArgsMap;
using PEBKAC::PebkacAuthenticator;
using PEBKAC::PebkacRequester;

// Constructor
PEBKAC::LatestPebkacsRequester::LatestPebkacsRequester(const PebkacAuthenticator & authPebkac,
													   int offset,
													   int limit,
													   QNetworkAccessManager & netManager) :
	PebkacRequester(GET, LATEST_PEBKACS_URL, authPebkac, netManager),
	offset(offset),
	limit(limit)
{}

// Building getParameters
ArgsMap PEBKAC::LatestPebkacsRequester::buildGETParameters() {
	ArgsMap getArgs = PebkacRequester::buildGETParameters();

	if (offset != OFFSET_DEFAULT_VALUE && limit != LIMIT_DEFAULT_VALUE) {
		getArgs.insert("offset", QString::number(offset));
		getArgs.insert("limit", QString::number(limit));
		pattern.append("/%2,%1");
	}

	return getArgs;
}
