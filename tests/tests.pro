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

QT            = core testlib

TARGET        = TestReynTests
TEMPLATE      = app
DESTDIR       = ../build

CONFIG       *= console
CONFIG       -= app_bundle
CONFIG       += testcase stl
win32:CONFIG -= debug_and_release debug_and_release_target

DEFINES      += SRCDIR=\\\"$$PWD/\\\"

MOC_DIR       = ../build/mocs/tests/
OBJECTS_DIR   = ../build/obj/tests/
MAKEFILE      = Makefile.tests


#---------------#
# libRT library #
#---------------#

REYN_TESTS_ROOT_FOLDER = $$system_path($$clean_path($${PWD}/../)/)

debug {
	LIBRT_LIB_FOLDER = $$system_path($${REYN_TESTS_ROOT_FOLDER}lib/ReynTests_Debug/)
} else:release {
	LIBRT_LIB_FOLDER = $$system_path($${REYN_TESTS_ROOT_FOLDER}lib/ReynTests/)
}

INCLUDEPATH   += $${REYN_TESTS_ROOT_FOLDER}include
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

SOURCES += \
