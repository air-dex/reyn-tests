/// @file twitterurls.cpp
/// @brief Implementation of the "Twitter" namespace part containing
/// Twitter URLs.
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

#include "twitterurls.hpp"

// NB : QString::fromUtf8(); is used to avoid problem with character conversion.

//////////////
// Accounts //
//////////////

// Verify credentials
QString LibRT::Twitter::VERIFY_CREDENTIALS_URL = QString::fromUtf8("https://api.twitter.com/1.1/account/verify_credentials.json");


///////////////
// Favorites //
///////////////

// Favorite a tweet
QString LibRT::Twitter::CREATE_FAVORITE_URL = QString::fromUtf8("https://api.twitter.com/1.1/favorites/create.json");

// Unfavorite a tweet
QString LibRT::Twitter::DELETE_FAVORITE_URL = QString::fromUtf8("https://api.twitter.com/1.1/favorites/destroy.json");

// Getting the timeline of the favorite tweets of a user
QString LibRT::Twitter::FAVORITE_TIMELINE_URL = QString::fromUtf8("https://api.twitter.com/1.1/favorites/list.json");


///////////
// OAuth //
///////////

// Getting a request token
QString LibRT::Twitter::REQUEST_TOKEN_URL = QString::fromUtf8("https://api.twitter.com/oauth/request_token");

// Authorizing the application
QString LibRT::Twitter::AUTHORIZE_URL = QString::fromUtf8("https://api.twitter.com/oauth/authorize");

// Authentication
QString LibRT::Twitter::AUTHENTICATE_URL = QString::fromUtf8("https://api.twitter.com/oauth/authenticate");

// Getting an access token
QString LibRT::Twitter::ACCESS_TOKEN_URL = QString::fromUtf8("https://api.twitter.com/oauth/access_token");


//////////////
// Searches //
//////////////

// Search request
QString LibRT::Twitter::SEARCH_URL = QString::fromUtf8("https://api.twitter.com/1.1/search/tweets.json");


///////////////
// Timelines //
///////////////

// Getting the timeline with friends tweets
QString LibRT::Twitter::HOME_TIMELINE_URL = QString::fromUtf8("https://api.twitter.com/1.1/statuses/home_timeline.json");

// Getting the timeline containing the user's mentions
QString LibRT::Twitter::MENTIONS_TIMELINE_URL = QString::fromUtf8("https://api.twitter.com/1.1/statuses/mentions_timeline.json");

// Getting the timeline with retweets retweeted by the user
QString LibRT::Twitter::RETWEETED_BY_ME_TIMELINE_URL = QString::fromUtf8("http://api.twitter.com/1/statuses/retweeted_by_me.json");


////////////
// Tweets //
////////////

// Deleting a tweet (or a retweet)
QString LibRT::Twitter::DELETE_TWEET_URL = QString::fromUtf8("https://api.twitter.com/1.1/statuses/destroy/:id.json");

// Retweeting a tweet
QString LibRT::Twitter::RETWEET_URL = QString::fromUtf8("https://api.twitter.com/1.1/statuses/retweet/:id.json");

// Getting informations about a given tweet
QString LibRT::Twitter::SHOW_TWEET_URL = QString::fromUtf8("https://api.twitter.com/1.1/statuses/show.json");

// Updating a tweet without medias
QString LibRT::Twitter::UPDATE_TWEET_URL = QString::fromUtf8("https://api.twitter.com/1.1/statuses/update.json");

// Updating a tweet with medias
QString LibRT::Twitter::UPDATE_TWEET_WITH_MEDIA_URL = QString::fromUtf8("https://upload.twitter.com/1.1/statuses/update_with_media.json");


///////////
// Users //
///////////

// Getting informations about a given user
QString LibRT::Twitter::SHOW_USER_URL = QString::fromUtf8("https://api.twitter.com/1.1/users/show.json");
