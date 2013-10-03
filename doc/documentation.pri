#---------------------------------------------------#
# documentation.pri                                 #
# .pri sub project file for (Doxygen) documentation #
# Author : Romain Ducher                            #
#---------------------------------------------------#

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

OTHER_FILES = \
	doc/Doxyfile.txt \
	doc/doxygen_log.txt \
	doc/html/index.html

#-----------------------#
# Documentation targets #
#-----------------------#

# DOXYGEN_CMD is the Doxygen executable with its absoulute path
win32 {
	DOXYGEN_CMD = C:/Program Files/doxygen/bin/doxygen.exe
} else:linux-g++ {
	DOXYGEN_CMD = /usr/bin/doxygen
}

DOXYGEN_CMD = $$system_path($${DOXYGEN_CMD})

# DOC_FOLDER : root folder for documentation
DOC_FOLDER = $$system_path($${LIBRT_FOLDER}doc/)

# Create doc
doc.target = doc
doc.commands = $${DOXYGEN_CMD} $${DOC_FOLDER}Doxyfile.txt

# Clean doc
cleandoc.target = cleandoc
cleandoc.commands = $${PYTHON_SCRIPT_CMD} cleanDoc

# Extra targets
QMAKE_EXTRA_TARGETS += doc cleandoc
