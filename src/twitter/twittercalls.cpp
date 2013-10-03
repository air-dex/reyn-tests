/// @file twittercalls.cpp
/// @brief Implementation of TwitterCalls
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2011, 2013 Romain Ducher
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

#include "twittercalls.hpp"
#include "requests/twitterrequests.hpp"

using LibRT::GenericCalls;
using LibRT::GenericRequester;
using LibRT::Twitter::TwitterCalls;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::AccessTokenRequester;
using LibRT::Twitter::AuthorizeRequester;
using LibRT::Twitter::DestroyTweetRequester;
using LibRT::Twitter::FavoriteRequester;
using LibRT::Twitter::FavoritesTimelineRequester;
using LibRT::Twitter::HomeTimelineRequester;
using LibRT::Twitter::MentionsTimelineRequester;
using LibRT::Twitter::PostTweetRequester;
using LibRT::Twitter::RequestTokenRequester;
using LibRT::Twitter::RetweetRequester;
using LibRT::Twitter::SearchRequester;
using LibRT::Twitter::ShowTweetRequester;
using LibRT::Twitter::ShowUserRequester;
using LibRT::Twitter::VerifyCredentialsRequester;

// Protected constructor
TwitterCalls::TwitterCalls(QObject * requester,
						   const TwitterAuthenticator &twitterOAuth,
						   QNetworkAccessManager & netManager) :
	GenericCalls(requester, netManager),
	oauthManager(twitterOAuth)
{}

// Destructor
TwitterCalls::~TwitterCalls() {}


///////////////////////
// Request launchers //
///////////////////////

//////////////
// Accounts //
//////////////

// Verifying credentials
void TwitterCalls::verifyCredentials(bool entities, bool skipStatus) {
	VerifyCredentialsRequester * requester = new VerifyCredentialsRequester(oauthManager,
																			entities,
																			skipStatus,
																			network);
	executeRequest(requester);
}


///////////////
// Favorites //
///////////////

// Favoriting a tweet
void TwitterCalls::favoriteTweet(qlonglong id, bool entities) {
	FavoriteRequester * requester = new FavoriteRequester(oauthManager,
														  true,
														  id,
														  entities,
														  network);
	executeRequest(requester);
}

// Retrieving the timeline with the favorite tweets of the userwhose ID is id.
void TwitterCalls::getFavoriteTimeline(qlonglong id,
									   qlonglong sinceID,
									   qlonglong maxID,
									   bool entities,
									   int count)
{
	FavoritesTimelineRequester * requester = new FavoritesTimelineRequester(oauthManager,
																			id,
																			sinceID,
																			maxID,
																			entities,
																			count,
																			network);
	executeRequest(requester);
}

// Retrieving the timeline with the favorite tweets of the user whose screen name is id.
void TwitterCalls::getFavoriteTimeline(QString username,
									   qlonglong sinceID,
									   qlonglong maxID,
									   bool entities,
									   int count)
{
	FavoritesTimelineRequester * requester = new FavoritesTimelineRequester(oauthManager,
																			username,
																			sinceID,
																			maxID,
																			entities,
																			count,
																			network);
	executeRequest(requester);
}

// Unavoriting a tweet
void TwitterCalls::unfavoriteTweet(qlonglong id, bool entities) {
	FavoriteRequester * requester = new FavoriteRequester(oauthManager,
														  false,
														  id,
														  entities,
														  network);
	executeRequest(requester);
}


///////////
// OAuth //
///////////

// Method for getting a request token
void TwitterCalls::requestToken() {
	RequestTokenRequester * requester = new RequestTokenRequester(oauthManager,
																  network);
	executeRequest(requester);
}

// Authorizing request Tokens
void TwitterCalls::authorize(bool forceLogin, QString writeLogin) {
	AuthorizeRequester * requester = new AuthorizeRequester(oauthManager,
															forceLogin,
															writeLogin,
															network);
	executeRequest(requester);
}

// Getting the access tokens
void TwitterCalls::accessToken() {
	AccessTokenRequester * requester = new AccessTokenRequester(oauthManager,
																network);
	executeRequest(requester);
}


//////////////
// Searches //
//////////////

// Method that launch searches
void TwitterCalls::search(QString q) {
	SearchRequester * requester = new SearchRequester(oauthManager, q, network);
	executeRequest(requester);
}


///////////////
// Timelines //
///////////////

// Retrieving the timeline with the tweets of the user's friends
void TwitterCalls::retrieveHomeTimeline(qlonglong sinceID,
										qlonglong maxID,
										bool trimUser,
										bool includeEntities,
										bool excludeReplies,
										int count,
										bool contributorsDetails)
{
	HomeTimelineRequester * requester = new HomeTimelineRequester(oauthManager,
																  sinceID,
																  maxID,
																  trimUser,
																  includeEntities,
																  excludeReplies,
																  count,
																  contributorsDetails,
																  network);
	executeRequest(requester);
}

// Retrieving the timeline with the containing the mentions of the user
void TwitterCalls::retrieveMentionsTimeline(qlonglong sinceID,
											qlonglong maxID,
											bool trimUser,
											bool includeEntities,
											int count,
											bool contributorsDetails)
{
	MentionsTimelineRequester * requester = new MentionsTimelineRequester(oauthManager,
																		  sinceID,
																		  maxID,
																		  trimUser,
																		  includeEntities,
																		  count,
																		  contributorsDetails,
																		  network);
	executeRequest(requester);
}


////////////
// Tweets //
////////////

// Destroying (deleting) a tweet
void TwitterCalls::destroyTweet(qlonglong tweetID, bool trimUser) {
	DestroyTweetRequester * requester = new DestroyTweetRequester(oauthManager,
																  tweetID,
																  trimUser,
																  network);
	executeRequest(requester);
}

// Retweeting a tweet
void TwitterCalls::retweet(qlonglong tweetID, bool trimUser) {
	RetweetRequester * requester = new RetweetRequester(oauthManager,
														tweetID,
														trimUser,
														network);
	executeRequest(requester);
}

// Showing a tweet
void TwitterCalls::showTweet(qlonglong tweetID,
							 bool entities,
							 bool trimUser,
							 bool includeMyRetweet)
{
	ShowTweetRequester * requester = new ShowTweetRequester(oauthManager,
															tweetID,
															entities,
															trimUser,
															includeMyRetweet,
															network);
	executeRequest(requester);
}

// Posting a tweet without media
void TwitterCalls::updateTweet(QString tweet,
							   qlonglong replyToTweetID,
							   float latitude,
							   float longitude,
							   QString reversePlace,
							   bool displayCoord,
							   bool trimUser)
{
	PostTweetRequester * requester = new PostTweetRequester(oauthManager,
															tweet,
															replyToTweetID,
															latitude,
															longitude,
															reversePlace,
															displayCoord,
															trimUser,
															network);
	executeRequest(requester);
}


///////////
// Users //
///////////

// Showing a user identified by its ID
void TwitterCalls::showUser(qlonglong userID, bool entities) {
	ShowUserRequester * requester = new ShowUserRequester(oauthManager,
														  userID,
														  entities,
														  network);
	executeRequest(requester);
}

// Showing a user identified by its screen name
void TwitterCalls::showUser(QString screenName, bool entities) {
	ShowUserRequester * requester = new ShowUserRequester(oauthManager,
														  screenName,
														  entities,
														  network);
	executeRequest(requester);
}
