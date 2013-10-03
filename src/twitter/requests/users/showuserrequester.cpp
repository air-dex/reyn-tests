/// @file showuserrequester.cpp
/// @brief Implementation of ShowUserRequester
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

#include "showuserrequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::ShowUserRequester;

// Constructor with the user ID
ShowUserRequester::ShowUserRequester(const TwitterAuthenticator &authManager,
									 qlonglong id,
									 bool entities,
									 QNetworkAccessManager &netManager) :
	TwitterRequester(GET, SHOW_USER_URL, authManager, netManager),
	idWay(LibRT::ID),
	userID(id),
	includeEntities(entities),
	screenName()
{}

// Constructor with the screen name
ShowUserRequester::ShowUserRequester(const TwitterAuthenticator & authManager,
									 QString name,
									 bool entities,
									 QNetworkAccessManager &netManager) :
	TwitterRequester(GET, SHOW_USER_URL, authManager, netManager),
	idWay(LibRT::SCREEN_NAME),
	userID(),
	includeEntities(entities),
	screenName(name)
{}

// Building getParameters
ArgsMap ShowUserRequester::buildGETParameters() {
	ArgsMap getParameters;

	if (idWay == LibRT::ID) {
		getParameters.insert("id", QString::number(userID));
	}

	getParameters.insert("include_entities", boolInString(includeEntities));

	if (idWay == LibRT::SCREEN_NAME) {
		getParameters.insert("screen_name", screenName);
	}

	return getParameters;

}
