/// @file httpargs.cpp
/// @brief Implementation of HTTPArgs.
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

#include "httpargs.hpp"

#include "../headersmap.hpp"
#include "../utils/connectionutils.hpp"

using LibRT::ArgsMap;

// Constructor
LibRT::HTTPArgs::HTTPArgs(ArgsMap args) :
	httpArgs(args)
{}

// Args of the struct built with the build(ArgsMap); method.
QString LibRT::HTTPArgs::getBuiltArgs() {
	return LibRT::buildQueryDatas(httpArgs);
}

// Getting httpArgs
ArgsMap LibRT::HTTPArgs::getHttpArgs() const {
	return httpArgs;
}
