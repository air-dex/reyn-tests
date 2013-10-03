#-----------------------------------------------------#
# sources.pri                                         #
# .pri Qt sub-project file for Reyn Tests source code #
# Author : Romain Ducher                              #
#-----------------------------------------------------#

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

# Building the library
TARGET        = ReynTests
TEMPLATE      = lib
DEFINES      += REYNTESTS_LIBRARY

CONFIG       += stl
win32:CONFIG -= debug_and_release debug_and_release_target

debug {
	DESTDIR   = ../lib/$${TARGET}_Debug
} else:release {
	DESTDIR   = ../lib/$${TARGET}
}


#---------#
# Version #
#---------#

VER_MAJ = 1
VER_MIN = 0
VER_PAT = 0

VERSION = $${VER_MAJ}.$${VER_MIN}.$${VER_PAT}


#-------------------------------#
# Temporary files for compiling #
#-------------------------------#

MOC_DIR          = ../build/mocs/src
OBJECTS_DIR      = ../build/obj/src


#---------#
# Sources #
#---------#

HEADERS += \
	reyntests_global.hpp \
	testutils.hpp \
	testresults.hpp \
	testentity.hpp \
	testcase.hpp \
	testsuite.hpp

SOURCES += \
	testutils.cpp \
	testresults.cpp \
	testentity.cpp \
	testcase.cpp \
	testsuite.cpp


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
