/// @file twitlongercalls.cpp
/// @brief Implementation of TwitLongerCalls
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

#include "twitlongercalls.hpp"
#include "requests/twitlongerrequests.hpp"

using LibRT::GenericCalls;
using LibRT::TwitLonger::TwitLongerCalls;
using LibRT::TwitLonger::PostToTwitLongerRequester;
using LibRT::TwitLonger::SendIDToTwitLongerRequester;
using LibRT::TwitLonger::TwitLongerAuthenticator;

// Constructor
TwitLongerCalls::TwitLongerCalls(QObject * requester,
								 const TwitLongerAuthenticator & twitlongerAuth,
								 QNetworkAccessManager & netManager) :
	GenericCalls(requester, netManager),
	twitlongerManager(twitlongerAuth)
{}

// Posting the long message on TwitLonger
void TwitLongerCalls::postOnTwitLonger(QString username,
									   QString message,
									   qlonglong replyToTweetID,
									   QString replyToUser)
{
	PostToTwitLongerRequester * requester = new PostToTwitLongerRequester(twitlongerManager,
																		  message,
																		  username,
																		  replyToTweetID,
																		  replyToUser,
																		  network);
	executeRequest(requester);
}

// Updating the informations on TwitLonger
void TwitLongerCalls::updateLongTweet(QString messageID, qlonglong tweetID) {
	SendIDToTwitLongerRequester * requester = new SendIDToTwitLongerRequester(twitlongerManager,
																			  messageID,
																			  tweetID,
																			  network);
	executeRequest(requester);
}
