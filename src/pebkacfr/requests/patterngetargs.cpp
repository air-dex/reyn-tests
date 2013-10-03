/// @file patterngetargs.cpp
/// @brief Implementation of PatternGetArgs
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2013 Romain Ducher
///
/// This file is part of LibRT.
///
/// LibRT is free software: you can redistribute it and/or modify it under
/// the terms of the GNU Lesser General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// LibRT is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
/// for more details.
///
/// You should have received a copy of the GNU Lesser General Public License
/// along with LibRT. If not, see <http://www.gnu.org/licenses/>.

#include "patterngetargs.hpp"

#include <QStringList>

namespace PEBKAC = LibRT::Pebkac;

using LibRT::ArgsMap;

// Constructor
PEBKAC::PatternGetArgs::PatternGetArgs(ArgsMap getParams, QString getPattern) :
	LibRT::GetArgs(getParams),
	pattern(getPattern)
{}

// Building the HTTP args with the elements of the struct.
QString PEBKAC::PatternGetArgs::getBuiltArgs() {
	// Extracting the pattern
	QStringList keys = httpArgs.keys();

	keys.sort();

	// Filling the pattern with alphabetical order
	for (QStringList::iterator it = keys.begin();
		 it != keys.end();
		  ++it)
	{
		pattern.arg(httpArgs.value(*it));
	}

	return pattern;
}
