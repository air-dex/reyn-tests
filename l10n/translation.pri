#----------------------------------------------#
# translation.pri                              #
# .pri sub project file for libRT translations #
# Author : Romain Ducher                       #
#----------------------------------------------#

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

TEMPLATE = subdirs

OTHER_FILES = \
	l10n/librt_en.ts \
	l10n/librt_fr.ts

#--------------#
# Translations #
#--------------#

TRANSLATIONS = librt_en.ts librt_fr.ts


#---------------------#
# Translation targets #
#---------------------#

# Folder containing translations
TR_FOLDER = $$system_path($${PWD}l10n/)

# TS files
FR_TS = $${TR_FOLDER}librt_fr.ts
EN_TS = $${TR_FOLDER}librt_en.ts

# QM files
FR_QM = $${TR_FOLDER}librt_fr.qm
EN_QM = $${TR_FOLDER}librt_en.qm
QM_TRFILES = $${TR_FOLDER}*.qm

# lupdate
#LUPDATE_CMD = lupdate -no-obsolete $${LIBRT_ROOT}
LUPDATE_CMD = lupdate -no-obsolete $${LIBRT_ROOT}libRT.pro
LUPDATE_FR = $${LUPDATE_CMD} -ts $${FR_TS}
LUPDATE_EN = $${LUPDATE_CMD} -ts $${EN_TS}

trupdate.target = trupdate
win32 {
	trupdate.commands = ($${LUPDATE_FR}) & ($${LUPDATE_EN})
}
linux-g++ {
	trupdate.commands = $${LUPDATE_FR} ; $${LUPDATE_EN}
}

# Do not try to translate Javascript Doxygen files
trupdate.depends = cleandoc

# lrelease
LRELEASE_FR = lrelease $${FR_TS}
LRELEASE_EN = lrelease $${EN_TS}

trrelease.target = trrelease
win32 {
	trrelease.commands = ($${LRELEASE_FR}) & ($${LRELEASE_EN})
}
linux-g++ {
	trrelease.commands = $${LRELEASE_FR} ; $${LRELEASE_EN}
}

# Deploy .qm files in build directories
trdeploy.target = trdeploy
trdeploy.commands = $${PYTHON_SCRIPT_CMD} l10nDeploy
trdeploy.depends = trupdate

# Delete .qm files
trclean.target = trclean
trclean.commands = $${PYTHON_SCRIPT_CMD} l10nClean

# Extra targets
QMAKE_EXTRA_TARGETS += trupdate trrelease trdeploy trclean
