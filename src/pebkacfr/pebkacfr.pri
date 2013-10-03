#--------------------------------------------------------#
# pebkacfr.pri                                           #
# .pri sub project file for libRT PEBKAC.fr source files #
# Author : Romain Ducher                                 #
#--------------------------------------------------------#

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

PEBKACFR_ROOT = pebkacfr/

SOURCES += \
	$${PEBKACFR_ROOT}pebkacconstants.cpp \
	$${PEBKACFR_ROOT}pebkacperiod.cpp \
	$${PEBKACFR_ROOT}pebkacauthenticator.cpp \
	$${PEBKACFR_ROOT}requests/patterngetargs.cpp \
	$${PEBKACFR_ROOT}requests/pebkacurls.cpp \
	$${PEBKACFR_ROOT}requests/pebkacrequester.cpp \
	$${PEBKACFR_ROOT}requests/allpebkacfrusersrequester.cpp \
	$${PEBKACFR_ROOT}requests/allpebkactagsrequester.cpp \
	$${PEBKACFR_ROOT}requests/floppebkacsrequester.cpp \
	$${PEBKACFR_ROOT}requests/getpebkacrequester.cpp \
	$${PEBKACFR_ROOT}requests/latestpebkacsrequester.cpp \
	$${PEBKACFR_ROOT}requests/pebkaccommentsrequester.cpp \
	$${PEBKACFR_ROOT}requests/userpebkacsrequester.cpp \
	$${PEBKACFR_ROOT}requests/pebkactagrequester.cpp \
	$${PEBKACFR_ROOT}requests/randompebkacsrequester.cpp \
	$${PEBKACFR_ROOT}requests/toppebkacsrequester.cpp \
	$${PEBKACFR_ROOT}pebkaccalls.cpp


HEADERS  += \
	$${PEBKACFR_ROOT}pebkacconstants.hpp \
	$${PEBKACFR_ROOT}pebkacperiod.hpp \
	$${PEBKACFR_ROOT}pebkacauthenticator.hpp \
	$${PEBKACFR_ROOT}requests/patterngetargs.hpp \
	$${PEBKACFR_ROOT}requests/pebkacurls.hpp \
	$${PEBKACFR_ROOT}requests/pebkacrequester.hpp \
	$${PEBKACFR_ROOT}requests/allpebkacfrusersrequester.hpp \
	$${PEBKACFR_ROOT}requests/allpebkactagsrequester.hpp \
	$${PEBKACFR_ROOT}requests/floppebkacsrequester.hpp \
	$${PEBKACFR_ROOT}requests/getpebkacrequester.hpp \
	$${PEBKACFR_ROOT}requests/latestpebkacsrequester.hpp \
	$${PEBKACFR_ROOT}requests/pebkaccommentsrequester.hpp \
	$${PEBKACFR_ROOT}requests/userpebkacsrequester.hpp \
	$${PEBKACFR_ROOT}requests/pebkactagrequester.hpp \
	$${PEBKACFR_ROOT}requests/randompebkacsrequester.hpp \
	$${PEBKACFR_ROOT}requests/toppebkacsrequester.hpp \
	$${PEBKACFR_ROOT}requests/pebkacrequesters.hpp \
	$${PEBKACFR_ROOT}pebkaccalls.hpp
