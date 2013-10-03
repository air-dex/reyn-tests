/// @file posttweetrequester.cpp
/// @brief Implementation of PostTweetRequester
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

#include "posttweetrequester.hpp"
#include "../../../base/utils/connectionutils.hpp"

using LibRT::ArgsMap;
using LibRT::boolInString;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::PostTweetRequester;

// Constructor
PostTweetRequester::PostTweetRequester(const TwitterAuthenticator &authManager,
									   QString status,
									   qlonglong replyTostatusID,
									   float lat,
									   float lon,
									   QString place,
									   bool showCoord,
									   bool userIDonly,
									   QNetworkAccessManager &netManager) :
	TwitterRequester(POST, UPDATE_TWEET_URL, authManager, netManager),
	tweet(status),
	replyToTweetID(replyTostatusID),
	trimUser(userIDonly),
	longitude(lon),
	latitude(lat),
	reversePlace(place),
	displayCoord(showCoord)
{}

// Building getParameters
ArgsMap PostTweetRequester::buildPOSTParameters() {
	ArgsMap postParameters;

	postParameters.insert("status", tweet);

	if (replyToTweetID != Twitter::FAKE_TWEET_ID) {
		postParameters.insert("in_reply_to_status_id", QString::number(replyToTweetID));
	}

	if (qAbs(latitude) <= LibRT::MAX_LATITUDE) {
		postParameters.insert("lat", QString::number(latitude));
	}

	if (qAbs(longitude) <= LibRT::MAX_LONGITUDE) {
		postParameters.insert("long", QString::number(longitude));
	}

	if (reversePlace != Twitter::FAKE_PLACE_ID) {
		postParameters.insert("place_id", reversePlace);
	}

	postParameters.insert("display_coordinates", boolInString(displayCoord));
	postParameters.insert("trim_user", boolInString(trimUser));

	return postParameters;
}
