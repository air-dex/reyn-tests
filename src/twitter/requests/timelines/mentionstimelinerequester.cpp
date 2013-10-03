/// @file mentionstimelinerequester.cpp
/// @brief Implementation of MentionsTimelineRequester
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

#include "mentionstimelinerequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::MentionsTimelineRequester;

// Constructor
MentionsTimelineRequester::MentionsTimelineRequester(const TwitterAuthenticator &authManager,
													 qlonglong oldestTweetID,
													 qlonglong youngestTweetID,
													 bool userIDonly,
													 bool withEntities,
													 int nbTweets,
													 bool withContributorsDetails,
													 QNetworkAccessManager &netManager) :
	TwitterRequester(GET, MENTIONS_TIMELINE_URL, authManager, netManager),
	count(nbTweets),
	sinceID(oldestTweetID),
	maxID(youngestTweetID),
	trimUser(userIDonly),
	includeEntities(withEntities),
	contributorsDetails(withContributorsDetails)
{}

// Building getParameters
ArgsMap MentionsTimelineRequester::buildGETParameters() {
	ArgsMap getParameters;

	if (count != Twitter::DEFAULT_TWEETS_COUNT) {
		getParameters.insert("count", QString::number(count));
	}

	if (sinceID > Twitter::FAKE_TWEET_ID) {
		getParameters.insert("since_id", QString::number(sinceID));
	}


	if (maxID > Twitter::FAKE_TWEET_ID) {
		getParameters.insert("max_id", QString::number(maxID));
	}

	getParameters.insert("trim_user", boolInString(trimUser));
	getParameters.insert("include_entities", boolInString(includeEntities));
	getParameters.insert("contributors_details", boolInString(contributorsDetails));

	return getParameters;
}
