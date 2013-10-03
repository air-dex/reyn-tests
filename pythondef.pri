#-----------------------------------------------------#
# pyhondef.pri                                        #
# .pri Qt sub-project file for extra targets purposes #
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

#--------------------------------------------#
# Python 3 Script with extra targets scripts #
#--------------------------------------------#

# Write your own path to python.exe here
win32 {
	PYTHON3_EXEC = C:\\Python32\\python.exe
} else:linux-g++ {
	PYTHON3_EXEC = /usr/bin/python3
}

PYTHON_SCRIPT_CMD = $${PYTHON3_EXEC} $$system_path($${PWD}/extratargetscripts.py)


