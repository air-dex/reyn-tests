/// @file verifycredentialsrequester.cpp
/// @brief Implementation of VerifyCredentialsRequester
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2012, 2013 Romain Ducher
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

#include "verifycredentialsrequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::VerifyCredentialsRequester;

// Constructor
VerifyCredentialsRequester::VerifyCredentialsRequester(const TwitterAuthenticator &authManager,
													   bool entities,
													   bool skipLastTweet,
													   QNetworkAccessManager &netManager) :
	TwitterRequester(GET, VERIFY_CREDENTIALS_URL, authManager, netManager),
	includeEntities(entities),
	skipStatus(skipLastTweet)
{}

// Building getParameters
ArgsMap VerifyCredentialsRequester::buildGETParameters() {
	ArgsMap getParameters;

	getParameters.insert("include_entities", boolInString(includeEntities));
	getParameters.insert("skip_status", boolInString(skipStatus));

	return getParameters;
}
