#-----------------------------------------------#
# tests.pro                                     #
# .pri Qt sub-project file for Reyn Tests tests #
# Author : Romain Ducher                        #
#-----------------------------------------------#

#--------------------------------------------------------------------------#
#                                                                          #
# Copyright 2013 Romain Ducher                                             #
#                                                                          #
# This file is part of Reyn Tests.                                         #
#                                                                          #
# Reyn Tests is free software: you can redistribute it and/or modify it    #
# under the terms of the GNU Lesser General Public License as published by #
# the Free Software Foundation, either version 3 of the License, or        #
# (at your option) any later version.                                      #
#                                                                          #
# Reyn Tests is distributed in the hope that it will be useful,            #
# but WITHOUT ANY WARRANTY; without even the implied warranty of           #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             #
# GNU Lesser General Public License for more details.                      #
#                                                                          #
# You should have received a copy of the GNU Lesser General Public License #
# along with Reyn Tests. If not, see <http://www.gnu.org/licenses/>.       #
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


#--------------------#
# Reyn Tests library #
#--------------------#

REYNTESTS_ROOT_FOLDER = $$system_path($$clean_path($${PWD}/../)/)

debug {
	REYNTESTS_LIB_FOLDER = $$system_path($${REYNTESTS_ROOT_FOLDER}lib/ReynTests_Debug/)
} else:release {
	REYNTESTS_LIB_FOLDER = $$system_path($${REYNTESTS_ROOT_FOLDER}lib/ReynTests/)
}

INCLUDEPATH   += $${REYNTESTS_ROOT_FOLDER}include
LIBS          += -L$${REYNTESTS_LIB_FOLDER} -lReynTests

# Extra tasks

include(../pythondef.pri)

# Deploying it in build folder for tests execution
deployReynTests.target = deployReynTests
debug:deployReynTests.commands = $${PYTHON_SCRIPT_CMD} deployReynTests debug
release:deployReynTests.commands = $${PYTHON_SCRIPT_CMD} deployReynTests release

# Cleaning the library
cleanReynTests.target = cleanReynTests
cleanReynTests.commands = $${PYTHON_SCRIPT_CMD} cleanReynTests

QMAKE_EXTRA_TARGETS += deployReynTests cleanReynTests


# TODO : the tests, of course !

HEADERS += \

SOURCES += \
