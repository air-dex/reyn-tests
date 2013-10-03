/// @file favoriterequester.cpp
/// @brief Implementation of FavoriteRequester
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

#include "favoriterequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::FavoriteRequester;

// Constructor
FavoriteRequester::FavoriteRequester(const TwitterAuthenticator &authManager,
									 bool favorited,
									 qlonglong id,
									 bool withEntities,
									 QNetworkAccessManager &netManager) :
	TwitterRequester(POST,
					 favorited ? CREATE_FAVORITE_URL : DELETE_FAVORITE_URL,
					 authManager,
					 netManager),
	isFavorited(favorited),
	tweetID(id),
	includeEntities(withEntities)
{}

// Building postParameters
ArgsMap FavoriteRequester::buildPOSTParameters() {
	ArgsMap postParameters;

	postParameters.insert("id", QString::number(tweetID));
	postParameters.insert("include_entities", boolInString(includeEntities));

	return postParameters;
}
