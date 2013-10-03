/// @file getargs.cpp
/// @brief Implementation of the GetArgs struct.
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

#include "getargs.hpp"

using LibRT::HTTPArgs;

// Constructor
LibRT::GetArgs::GetArgs(LibRT::ArgsMap args) : HTTPArgs(args) {}

// Building the whole url for the request
QUrl LibRT::GetArgs::getRequestURL(QString baseURL) {
	QString getArguments = this->getBuiltArgs();

	QString finalURL = baseURL;

	if (!getArguments.isEmpty()) {
		finalURL.append(getArguments);
	}

	return QUrl(finalURL);
}

// Args of the struct built with the build(ArgsMap); method.
QString LibRT::GetArgs::getBuiltArgs() {
	QString builtArgs = HTTPArgs::getBuiltArgs();

	if (!builtArgs.isEmpty()) {
		builtArgs.prepend('?');
	}

	return builtArgs;
}
