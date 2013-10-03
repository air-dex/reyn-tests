#------------------------------------------#
# tests.pri                                #
# .pri Qt sub-project file for libRT tests #
# Author : Romain Ducher                   #
#------------------------------------------#

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

QT           += core network webkitwidgets xml testlib
QT           -= gui

TARGET        = TestLibRT
TEMPLATE      = app
DESTDIR       = ../build

CONFIG       *= console
CONFIG       -= app_bundle
CONFIG       += testcase
CONFIG       += stl
win32:CONFIG -= debug_and_release debug_and_release_target

DEFINES      += SRCDIR=\\\"$$PWD/\\\"

MOC_DIR       = ../build/mocs/tests/
OBJECTS_DIR   = ../build/obj/tests/
MAKEFILE      = Makefile.tests


#---------------#
# libRT library #
#---------------#

LIBRT_ROOT_FOLDER = $$system_path($$clean_path($${PWD}/../)/)

debug {
	LIBRT_LIB_FOLDER = $$system_path($${LIBRT_ROOT_FOLDER}lib/libRT_Debug/)
} else:release {
	LIBRT_LIB_FOLDER = $$system_path($${LIBRT_ROOT_FOLDER}lib/libRT/)
}

INCLUDEPATH   += $${LIBRT_ROOT_FOLDER}include
LIBS          += -L$${LIBRT_LIB_FOLDER} -llibRT

# Extra tasks

include(../pythondef.pri)

# Deploying it in build folder for tests execution
deployLib.target = deployLib
debug:deployLib.commands = $${PYTHON_SCRIPT_CMD} deployLib debug
release:deployLib.commands = $${PYTHON_SCRIPT_CMD} deployLib release

# Cleaning the library
cleanLib.target = cleanLib
cleanLib.commands = $${PYTHON_SCRIPT_CMD} cleanLibRT

QMAKE_EXTRA_TARGETS += deployLib cleanLib


# TODO : the tests, of course !
# TODO : location of tests for third services

HEADERS += \
	testutils.hpp \
	testresults.hpp \
	testentity.hpp \
	testcase.hpp \
	testsuite.hpp \
	base/parsers/jsonparsertests.hpp \
	base/parsers/parserstests.hpp \
	base/basetests.hpp \
	librttests.hpp

SOURCES += \
	testutils.cpp \
	testresults.cpp \
	testentity.cpp \
	testcase.cpp \
	testsuite.cpp \
	base/parsers/jsonparsertests.cpp \
	base/parsers/parserstests.cpp \
	base/basetests.cpp \
	librttests.cpp \
	testmain.cpp


#-----------------------------------#
# Files with mocked datas for tests #
#-----------------------------------#

# JSON parsing

JSON_DATA_FOLDER= base/parsers/json_datas/

JSON_DATA_FILES= \
	$${JSON_DATA_FOLDER}bad_list_utf8.json \
	$${JSON_DATA_FOLDER}bad_obj_utf8.json \
	$${JSON_DATA_FOLDER}good_list_latin1.json \
	$${JSON_DATA_FOLDER}good_list_utf8.json \
	$${JSON_DATA_FOLDER}good_obj_utf8.json

OTHER_FILES += $${JSON_DATA_FILES}

# XML parsing

# TODO : example files for XML parsing

# HTML parsing

# TODO : example files for HTML parsing

# Query parsing

# TODO : example files for Query parsing

# Files for PEBKAC.fr

# TODO : files with raw request results for PEBKAC.fr

# Files for Twitter

# TODO : files with raw request results for Twitter

# Files for TwitLonger

# TODO : files with raw request results for TwitLonger
