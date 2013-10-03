#------------------------------------------------------#
# twitter.pri                                          #
# .pri sub project file for libRT Twitter source files #
# Author : Romain Ducher                               #
#------------------------------------------------------#

#--------------------------------------------------------------------------#
#                                                                          #
# Copyright 2013 Romain Ducher                                             #
#                                                                          #
# This file is part of libRT.                                              #
#                                                                          #
# libRT is free software: you can redistribute it and/or modify it under   #
# the terms of the GNU Lesser General Public License as published by       #
# the Free Software Foundation, either version 3 of the License, or        #
# (at your option) any later version.                                      #
#                                                                          #
# libRT is distributed in the hope that it will be useful,                 #
# but WITHOUT ANY WARRANTY; without even the implied warranty of           #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             #
# GNU Lesser General Public License for more details.                      #
#                                                                          #
# You should have received a copy of the GNU Lesser General Public License #
# along with libRT. If not, see <http://www.gnu.org/licenses/>.            #
#                                                                          #
#--------------------------------------------------------------------------#

TWITTER_ROOT = twitter/

SOURCES += \
	$${TWITTER_ROOT}twitterconstants.cpp \
	$${TWITTER_ROOT}twitterauthenticator.cpp \
	$${TWITTER_ROOT}requests/twitterurls.cpp \
	$${TWITTER_ROOT}requests/twitterrequester.cpp \
	$${TWITTER_ROOT}requests/accounts/verifycredentialsrequester.cpp \
	$${TWITTER_ROOT}requests/favorites/favoriterequester.cpp \
	$${TWITTER_ROOT}requests/favorites/favoritestimelinerequester.cpp \
	$${TWITTER_ROOT}requests/oauth/oauthrequester.cpp \
	$${TWITTER_ROOT}requests/oauth/requesttokenrequester.cpp \
	$${TWITTER_ROOT}requests/oauth/authorizerequester.cpp \
	$${TWITTER_ROOT}requests/oauth/accesstokenrequester.cpp \
	$${TWITTER_ROOT}requests/searches/searchrequester.cpp \
	$${TWITTER_ROOT}requests/timelines/hometimelinerequester.cpp \
	$${TWITTER_ROOT}requests/timelines/mentionstimelinerequester.cpp \
	$${TWITTER_ROOT}requests/tweets/destroytweetrequester.cpp \
	$${TWITTER_ROOT}requests/tweets/posttweetrequester.cpp \
	$${TWITTER_ROOT}requests/tweets/retweetrequester.cpp \
	$${TWITTER_ROOT}requests/tweets/showtweetrequester.cpp \
	$${TWITTER_ROOT}requests/users/showuserrequester.cpp \
	$${TWITTER_ROOT}twittercalls.cpp


HEADERS  += \
	$${TWITTER_ROOT}twitterconstants.hpp \
	$${TWITTER_ROOT}twitterauthenticator.hpp \
	$${TWITTER_ROOT}requests/twitterurls.hpp \
	$${TWITTER_ROOT}requests/twitterrequester.hpp \
	$${TWITTER_ROOT}requests/accounts/verifycredentialsrequester.hpp \
	$${TWITTER_ROOT}requests/favorites/favoriterequester.hpp \
	$${TWITTER_ROOT}requests/favorites/favoritestimelinerequester.hpp \
	$${TWITTER_ROOT}requests/oauth/oauthrequester.hpp \
	$${TWITTER_ROOT}requests/oauth/requesttokenrequester.hpp \
	$${TWITTER_ROOT}requests/oauth/authorizerequester.hpp \
	$${TWITTER_ROOT}requests/oauth/accesstokenrequester.hpp \
	$${TWITTER_ROOT}requests/searches/searchrequester.hpp \
	$${TWITTER_ROOT}requests/timelines/hometimelinerequester.hpp \
	$${TWITTER_ROOT}requests/timelines/mentionstimelinerequester.hpp \
	$${TWITTER_ROOT}requests/tweets/destroytweetrequester.hpp \
	$${TWITTER_ROOT}requests/tweets/posttweetrequester.hpp \
	$${TWITTER_ROOT}requests/tweets/retweetrequester.hpp \
	$${TWITTER_ROOT}requests/tweets/showtweetrequester.hpp \
	$${TWITTER_ROOT}requests/users/showuserrequester.hpp \
	$${TWITTER_ROOT}requests/twitterrequests.hpp \
	$${TWITTER_ROOT}twittercalls.hpp
