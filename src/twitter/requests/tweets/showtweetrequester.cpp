/// @file showtweetrequester.cpp
/// @brief Implementation of ShowTweetRequester
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

#include "showtweetrequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::ShowTweetRequester;

// Constructor
ShowTweetRequester::ShowTweetRequester(const TwitterAuthenticator &authManager,
									   qlonglong id,
									   bool entities,
									   bool userIdsOnly,
									   bool withRTid,
									   QNetworkAccessManager &netManager) :
	TwitterRequester(GET, SHOW_TWEET_URL, authManager, netManager),
	tweetID(id),
	includeEntities(entities),
	trimUser(userIdsOnly),
	includeMyRetweet(withRTid)
{}

// Virtual method building getParameters
ArgsMap ShowTweetRequester::buildGETParameters() {
	ArgsMap getParameters;

	getParameters.insert("id", QString::number(tweetID));
	getParameters.insert("include_entities", boolInString(includeEntities));
	getParameters.insert("trim_user", boolInString(trimUser));
	getParameters.insert("include_my_retweet", boolInString(includeMyRetweet));

	return getParameters;
}