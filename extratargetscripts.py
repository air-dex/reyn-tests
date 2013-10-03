#!/usr/bin/python3

# -*-coding:Latin-1 -*

import os
import os.path as ospath
import shutil
from sys import argv as argz
from fnmatch import fnmatch as extmatch


# Root of libRT project
librtpath = os.getcwd()


#------------------#
# /include headers #
#------------------#

includepath = ospath.join(librtpath, "include", "libRT")
srcpath = ospath.join(librtpath, "src")


def isHeader(file):
    """Is it a header ?"""
    return ospath.isfile(file) and (extmatch(file, "*.hpp") or extmatch(file, "*.tpp"))
# End isHeader


def importAllHeaders():
    """Imports all headers in includepath (/include/libRT/)"""

    # Function to copy all the headers of a given service
    def importHeaders(service):
        """For headers imports of a given service"""

        # Function to copy headers of a given folder
        def copyHeader(folder, dst):
            """Copies the content of folder into dst. dst might exist or not."""
            # Creates dst if necessary
            if not ospath.exists(dst):
                os.mkdir(dst)

            # Looking at what is inside the folder
            contentList = os.listdir(folder)

            # Copy each element
            for dirContent in contentList:
                fullContentPath = ospath.join(folder, dirContent)

                if ospath.isdir(fullContentPath):
                    # Directory : recursive call in the subfolder
                    newDst = ospath.join(dst, dirContent)

                    if not ospath.exists(newDst):
                        os.mkdir(newDst)

                    copyHeader(fullContentPath, newDst)
                elif isHeader(fullContentPath):
                    # File is a header
                    shutil.copy2(fullContentPath, dst)
        # End copyHeader

        # Copy .hpp headers
        sourcesdir = ospath.join(srcpath, service)
        includedir = ospath.join(includepath, service)

        # The copy
        copyHeader(sourcesdir, includedir)
    # End importHeaders

    # For Base imports
    importHeaders("base")

    # For Pebkac.fr imports
    importHeaders("pebkacfr")

    # For Twitter imports
    importHeaders("twitter")

    # For TwitLonger imports
    importHeaders("twitlonger")
# End importAllHeaders


def removeHeaders():
    """Remove headers"""
    # Function to remove all the headers
    def removeDirHeaders(folder):
        """Remove headers in a folder"""
        folderContent = [ospath.join(folder, folderElt) for folderElt in os.listdir(folder)]
    
        for folderElt in folderContent:
            if ospath.isdir(folderElt):
                # Remove headers of this folder
                removeDirHeaders(folderElt)
            elif isHeader(folderElt):
                # Remove header
                os.remove(folderElt)
    
        # If the folder is now empty, delete it
        if len(os.listdir(folder)) == 0:
            os.rmdir(folder)
    # End removeDirHeaders
    
    removeDirHeaders(includepath)
# End removeHeaders


#-----------------------#
# Doxygen documentation #
#-----------------------#

def removeDoc():
    """Removes Doxygen documentation"""
    docDir = ospath.join(librtpath, "doc")

    def removeFormat(doxygenFormat):
        """Removes all the doc for a given format"""
        formatDir = ospath.join(docDir, doxygenFormat)

        formatDirContent = [ospath.join(formatDir, elt) for elt in os.listdir(formatDir)]

        for folderElt in formatDirContent:
            if ospath.isdir(folderElt):
                shutil.rmtree(folderElt, ignore_errors=True)
            elif ospath.isfile(folderElt):
                os.remove(folderElt)
    # End removeFormat

    # Remove HTML
    removeFormat("html")

# End removeDoc


#--------------#
# Translations #
#--------------#

l10nPath = ospath.join(librtpath, "l10n")
libPath = {
	"debug": ospath.join(librtpath, "lib", "libRT_Debug"),
	"release": ospath.join(librtpath, "lib", "libRT"),
}

def isQMFile(l10nFile):
    """Is the file a .qm file ?"""
    return extmatch(l10nFile, "*.qm")
# End isQMFile


def deployL10N():
    """Deploy .qm files"""
    # Debug
    [shutil.copy2(ospath.join(l10nPath, l10nFile), libPath["debug"]) for l10nFile in os.listdir(l10nPath) if isQMFile(l10nFile)]
    
    # Release
    [shutil.copy2(ospath.join(l10nPath, l10nFile), libPath["release"]) for l10nFile in os.listdir(l10nPath) if isQMFile(l10nFile)]
# End deployL10N


def cleanL10N():
    """Removes .qm files"""
    # QM files in /lib/libRT_Debug
    [os.remove(ospath.join(libPath["debug"], qmFile)) for qmFile in os.listdir(libPath["debug"]) if isQMFile(qmFile)]
    
    # QM files in /lib/libRT
    [os.remove(ospath.join(libPath["release"], qmFile)) for qmFile in os.listdir(libPath["release"]) if isQMFile(qmFile)]

    # QM files in /l10n
    [os.remove(ospath.join(l10nPath, qmFile)) for qmFile in os.listdir(l10nPath) if isQMFile(qmFile)]
# End deployL10N


#-------------------------------------------------------#
# LibRT shared library in the /build folder (for tests) #
#-------------------------------------------------------#

buildPath = ospath.join(librtpath, "build")

def isLibFile(libFile):
    """Is this file a libfile"""
    libExt = {
        "windows": "*.dll",
        "linux": "lib*.so*"
    }
    
    return True in [extmatch(libFile, pattern) for pattern in libExt.values()]
# End isLibFile

def deployLib(*args):
    """Deploying the LibRT shared library in the executable folder."""
    if args != []:
        buildmode = args[0]
        [shutil.copy2(ospath.join(libPath[buildMode], libFile), buildPath) for libFile in os.listdir(libPath[buildMode]) if isLibFile(libFile)]
    else:
        print("Usage : [python] build/builinclude.py deployLibRT debug|release")
# End deployLib


def cleanLib():
    """Removes Shared libraries files in /build"""
    [os.remove(ospath.join(buildPath, libFile)) for libFile in os.listdir(buildPath) if isLibFile(libFile)]
# End deployL10N


#---------------------------#
# Erase all generated stuff #
#---------------------------#

def skullcrush():
    """Erases all the stuff generated by qmake and make"""
    # /build content
    for buildContent in [ospath.join(buildPath, buildFile) for buildFile in os.listdir(buildPath)]:
        if ospath.isdir(buildContent):
            shutil.rmtree(buildContent)
        else:
            os.remove(buildContent)
    
    cleanL10N()
    cleanLib()
    removeHeaders()
    removeDoc()
    
    # Makefiles
    os.remove(ospath.join(librtpath, "src", "Makefile.sources"))
    os.remove(ospath.join(librtpath, "tests", "Makefile.tests"))
    os.remove(ospath.join(librtpath, "Makefile"))
# End skullcrush


#------#
# Main #
#------#

# Actions that can be made by the script
actionz = {
    "copyHeaders":  importAllHeaders,   # Copy headers in /include folder
    "cleanHeaders": removeHeaders,      # Remove headers in /include folder
    "cleanDoc":     removeDoc,          # Clean Doxygen documentation
    "l10nDeploy":   deployL10N,         # Deploy *.qm translation binaries
    "l10nClean":    cleanL10N,          # Removes *.qm translation binaries
    "deployLibRT":  deployLib,          # Deploys LibRT in the executable directory. Takes the build mode (debug or release) as argument
    "cleanLibRT":   cleanLib,           # Cleans LibRT shared libraries (.so or .dll) in the executable directory.
    "crush":        skullcrush          # Erases all the stuff generated by qmake and make.
}

def main():
    """Main"""
    argc = len(argz)
    if argc < 2 :
        print("Usage : [python3] extratargetscripts.py action arg1 [arg2 ... argN]")
        return

    action = argz[1]

    if action in actionz.keys():
        actionz[action](*argz[2:])
    else:
        print("Unknown action for '{0}'. Available actions are : {1}.".format(action, ", ".join(actionz.keys())))
# End main()


if __name__ == '__main__':
    main()

