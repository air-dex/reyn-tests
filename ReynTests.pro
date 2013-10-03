#-------------------------------------#
# ReynTests.pro                       #
# .pro Qt project file for Reyn Tests #
# Author : Romain Ducher              #
#-------------------------------------#

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

MAKEFILE      = Makefile
win32:CONFIG -= debug_and_release debug_and_release_target

#---------#
# Subdirs #
#---------#

TEMPLATE = subdirs

SUBDIRS = \
	src   \		# C++ sources
	tests		# Tests


#-------------#
# Source code #
#-------------#

# Source code
src.file = src/sources.pro

buildinclude.target = buildinclude
buildinclude.commands = make -f src/Makefile.sources buildinclude

cleaninclude.target = cleaninclude
cleaninclude.commands = make -f src/Makefile.sources cleaninclude

QMAKE_EXTRA_TARGETS += buildinclude cleaninclude

# Tests
#tests.depends = src

deployReynTests.target = deployReynTests
deployReynTests.commands = make -f tests/Makefile.tests deployReynTests

cleanReynTests.target = cleanReynTests
cleanReynTests.commands = make -f tests/Makefile.tests cleanReynTests

QMAKE_EXTRA_TARGETS += deployReynTests cleanReynTests


#--------------------------#
# Non coding project parts #
#--------------------------#

REYNTESTS_ROOT= $$system_path($${PWD}/)

include(pythondef.pri)

# Documentation targets
include(doc/documentation.pri)

# Translations targets
include(l10n/translation.pri)


# Erasing all generated stuff
crush.target = crush
crush.commands = $${PYTHON_SCRIPT_CMD} crush

QMAKE_EXTRA_TARGETS += crush


#-------------#
# Other files #
#-------------#

OTHER_FILES += \
	.bzrignore \
	extratargetscripts.py \
	pythondef.pri \
	doc/documentation.pri \
	l10n/translation.pri \
	src/sources.pro \
	tests/tests.pro


#----------------------#
# Installs the library #
#----------------------#
unix:!symbian {
	maemo5 {
		target.path = /opt/usr/lib
	} else {
		target.path = /usr/lib
	}
	INSTALLS += target
}
