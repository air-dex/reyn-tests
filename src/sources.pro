#------------------------------------------------#
# sources.pri                                    #
# .pri Qt sub-project file for libRT source code #
# Author : Romain Ducher                         #
#------------------------------------------------#

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

QT           += core network webkitwidgets xml
QT           -= gui

# Building the library
TARGET        = libRT
TEMPLATE      = lib
DEFINES      += LIBRT_LIBRARY

debug {
	DESTDIR   = ../lib/libRT_Debug
} else:release {
	DESTDIR   = ../lib/libRT
}

win32:CONFIG -= debug_and_release debug_and_release_target


#---------#
# Version #
#---------#

VERSION = 0.4.0

VER_MAJ = 0
VER_MIN = 4
VER_PAT = 0


#-------------------------------#
# Temporary files for compiling #
#-------------------------------#

MOC_DIR          = ../build/mocs/src
OBJECTS_DIR      = ../build/obj/src
#MAKEFILE         = Makefile.sources

#-------------------------------------------------#
# Core sources in libRT (used by all the services #
#-------------------------------------------------#

BASE_ROOT = base/

SOURCES += \
	$${BASE_ROOT}utils/librtconstants.cpp \
	$${BASE_ROOT}utils/connectionutils.cpp \
	$${BASE_ROOT}parsers/htmlparser.cpp \
	$${BASE_ROOT}parsers/jsonparser.cpp \
	$${BASE_ROOT}parsers/oauthparser.cpp \
	$${BASE_ROOT}parsers/xmlparser.cpp \
	$${BASE_ROOT}networkresult.cpp \
	$${BASE_ROOT}authenticators/apikeyauthenticator.cpp \
	$${BASE_ROOT}authenticators/oauth/oauthutils.cpp \
	$${BASE_ROOT}authenticators/oauth/oauthauthenticator.cpp \
	$${BASE_ROOT}authenticators/oauth/oauth10aauthenticator.cpp \
	$${BASE_ROOT}authenticators/oauth/oauth2authenticator.cpp \
	$${BASE_ROOT}communicators/httpargs.cpp \
	$${BASE_ROOT}communicators/getargs.cpp \
	$${BASE_ROOT}communicators/communicator.cpp \
	$${BASE_ROOT}resultwrapper.cpp \
	$${BASE_ROOT}requests/communicatormanager.cpp \
	$${BASE_ROOT}requests/genericrequester.cpp \
	$${BASE_ROOT}calls/requestermanager.cpp \
	$${BASE_ROOT}calls/genericcalls.cpp


HEADERS  += \
	$${BASE_ROOT}librt_global.hpp \
	$${BASE_ROOT}utils/httpcode.hpp \
	$${BASE_ROOT}utils/librtconstants.hpp \
	$${BASE_ROOT}utils/connectionutils.hpp \
	$${BASE_ROOT}parsers/genericparser.hpp \
	$${BASE_ROOT}parsers/htmlparser.hpp \
	$${BASE_ROOT}parsers/jsonparser.hpp \
	$${BASE_ROOT}parsers/oauthparser.hpp \
	$${BASE_ROOT}parsers/xmlparser.hpp \
	$${BASE_ROOT}httprequesttype.hpp \
	$${BASE_ROOT}headersmap.hpp \
	$${BASE_ROOT}networkresult.hpp \
	$${BASE_ROOT}responseinfos.hpp \
	$${BASE_ROOT}authenticators/apikeyauthenticator.hpp \
	$${BASE_ROOT}authenticators/basicauthenticators.hpp \
	$${BASE_ROOT}authenticators/oauth/oauthutils.hpp \
	$${BASE_ROOT}authenticators/oauth/oauthauthenticator.hpp \
	$${BASE_ROOT}authenticators/oauth/oauth10aauthenticator.hpp \
	$${BASE_ROOT}authenticators/oauth/oauth2authenticator.hpp \
	$${BASE_ROOT}communicators/httpargs.hpp \
	$${BASE_ROOT}communicators/getargs.hpp \
	$${BASE_ROOT}communicators/communicator.hpp \
	$${BASE_ROOT}networkresulttype.hpp \
	$${BASE_ROOT}requestresult.hpp \
	$${BASE_ROOT}resultwrapper.hpp \
	$${BASE_ROOT}requests/identificationway.hpp \
	$${BASE_ROOT}requests/communicatormanager.hpp \
	$${BASE_ROOT}requests/genericrequester.hpp \
	$${BASE_ROOT}calls/requestinfos.hpp \
	$${BASE_ROOT}calls/requestermanager.hpp \
	$${BASE_ROOT}calls/genericcalls.hpp

#----------------------------------------#
# Third party services included in libRT #
#----------------------------------------#

# Twitter
include(twitter/twitter.pri)

# Twitlonger
include(twitlonger/twitlonger.pri)

# Pebkac.fr
include(pebkacfr/pebkacfr.pri)

#-------------#
# Other files #
#-------------#

OTHER_FILES += \
	pebkacfr/pebkacfr.pri \
	twitlonger/twitlonger.pri \
	twitter/twitter.pri


#-----------------------------#
# /include folder extra tasks #
#-----------------------------#

include(../pythondef.pri)

#----------#
# Building #
#----------#

buildinclude.target = buildinclude
buildinclude.commands = $${PYTHON_SCRIPT_CMD} copyHeaders

#----------#
# Cleaning #
#----------#

cleaninclude.target = cleaninclude
cleaninclude.commands = $${PYTHON_SCRIPT_CMD} cleanHeaders

QMAKE_EXTRA_TARGETS += buildinclude cleaninclude
