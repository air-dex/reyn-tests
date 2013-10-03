/// @file destroytweetrequester.cpp
/// @brief Implementation of DestroyTweetRequester
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

#include "destroytweetrequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::DestroyTweetRequester;

// Constructor
DestroyTweetRequester::DestroyTweetRequester(const TwitterAuthenticator &authManager,
											 qlonglong statusID,
											 bool userIDonly,
											 QNetworkAccessManager &netManager) :
	TwitterRequester(POST, DELETE_TWEET_URL, authManager, netManager),
	tweetID(statusID),
	trimUser(userIDonly)
{
	// Replacing ":id" in the URL with the tweet ID
	requestURL.replace(":id", QString::number(tweetID));
}

// Building postParameters
ArgsMap DestroyTweetRequester::buildPOSTParameters() {
	ArgsMap postParameters;

	postParameters.insert("id", QString::number(tweetID));
	postParameters.insert("trim_user", boolInString(trimUser));

	return postParameters;
}
