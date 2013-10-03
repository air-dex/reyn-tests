#--------------------------------------------------#
# twitlonger.pri                                   #
# .pri sub project file for libRT Twitlonger files #
# Author : Romain Ducher                           #
#--------------------------------------------------#

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

TWITLONGER_ROOT = twitlonger/

SOURCES += \
	$${TWITLONGER_ROOT}twitlongerconstants.cpp \
	$${TWITLONGER_ROOT}twitlongerauthenticator.cpp \
	$${TWITLONGER_ROOT}requests/twitlongerurls.cpp \
	$${TWITLONGER_ROOT}requests/twitlongerrequester.cpp \
	$${TWITLONGER_ROOT}requests/posttotwitlongerrequester.cpp \
	$${TWITLONGER_ROOT}requests/sendidtotwitlongerrequester.cpp \
	$${TWITLONGER_ROOT}twitlongercalls.cpp


HEADERS  += \
	$${TWITLONGER_ROOT}twitlongerconstants.hpp \
	$${TWITLONGER_ROOT}twitlongerauthenticator.hpp \
	$${TWITLONGER_ROOT}requests/twitlongerurls.hpp \
	$${TWITLONGER_ROOT}requests/twitlongerrequester.hpp \
	$${TWITLONGER_ROOT}requests/posttotwitlongerrequester.hpp \
	$${TWITLONGER_ROOT}requests/sendidtotwitlongerrequester.hpp \
	$${TWITLONGER_ROOT}requests/twitlongerrequests.hpp \
	$${TWITLONGER_ROOT}twitlongercalls.hpp
