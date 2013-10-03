/// @file randompebkacsrequester.cpp
/// @brief Implementation of RandomPebkacsRequester
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

#include "randompebkacsrequester.hpp"
#include "pebkacurls.hpp"

using LibRT::ArgsMap;
using PEBKAC::PebkacRequester;
using PEBKAC::PebkacAuthenticator;

// Constructor
PEBKAC::RandomPebkacsRequester::RandomPebkacsRequester(const PebkacAuthenticator &authPebkac,
													   int nbPebkacs,
													   QNetworkAccessManager &netManager) :
	PebkacRequester(GET, RANDOM_PEBKACS_URL, authPebkac, netManager),
	count(nbPebkacs)
{}

// Building getParameters
ArgsMap PEBKAC::RandomPebkacsRequester::buildGETParameters() {
	ArgsMap getArgs = PebkacRequester::buildGETParameters();

	if (count != LIMIT_DEFAULT_VALUE){
		getArgs.insert("count",  QString::number(count));
		pattern.append("/%1");
	}

	return getArgs;
}

