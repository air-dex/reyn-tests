/// @file connectionutils.hpp
/// @brief Header with useful methods
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2011, 2013 Romain Ducher
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

#ifndef CONNECTIONUTILS_HPP
#define CONNECTIONUTILS_HPP

#include <QByteArray>
#include <QColor>
#include <QDataStream>
#include <QString>
#include "../httprequesttype.hpp"
#include "../librt_global.hpp"
#include "../headersmap.hpp"

namespace LibRT {
	///////////////////////
	// String convertion //
	///////////////////////

	/// @fn LIBRTSHARED_EXPORT QString requestTypeToString(LibRT::HTTPRequestType type)
	/// @brief Converting a RequestType into a QString
	/// @param type The RequestType
	/// @return The corresponding QString
	LIBRTSHARED_EXPORT QString requestTypeToString(HTTPRequestType type);

	/// @fn QString LIBRTSHARED_EXPORT boolInString(bool b);
	/// @brief Converting a bool into a QString
	/// @param b The boolean
	/// @return The corresponding QString
	LIBRTSHARED_EXPORT QString boolInString(bool b);


	//////////////////
	// Miscanellous //
	//////////////////

	/// @fn LIBRTSHARED_EXPORT bool ouBien(bool a, bool b);
	/// @brief Logical XOR : <code>a XOR b == a && !b || !a && b</code>
	/// @param a 1st bool
	/// @param b 2nd bool
	/// @returns a XOR b
	LIBRTSHARED_EXPORT bool ouBien(bool a, bool b);

	/// @fn LIBRTSHARED_EXPORT QString formatParam(QString name, QString value,
	///											   bool putDoubleQuotes = false);
	/// @brief Method for formatting parameters in the Authorization header,
	/// for GET and POST request parameters, and in the signature.
	///
	/// The process of how formatting parameters is described
	/// <a href="https://dev.twitter.com/docs/auth/authorizing-request">here
	/// </a> for the Authorization header and
	/// <a href="https://dev.twitter.com/docs/auth/creating-signature">here
	/// </a> for the signature. The difference between these two algorithm
	/// is that double quotes '"' surrounds the percent encoded value for
	/// the Authorization Header and not for the signature.
	/// @param name Name of the parameter
	/// @param value Value of the parameter
	/// @param putDoubleQuotes Boolean indicating if double quotes have to
	/// surround the percent encoded value.
	/// @return The formatted parameters
	LIBRTSHARED_EXPORT QString formatParam(QString name, QString value,
										   bool putDoubleQuotes = false);

	/// @fn LIBRTSHARED_EXPORT QString buildQueryDatas(ArgsMap argsMap);
	/// @brief Building the string that will contain all the arguments
	/// of the given ArgsMap just like in an URL.
	/// @param argsMap The argument map
	/// @return A QString representation looks like val1=arg1&val2=arg2...
	LIBRTSHARED_EXPORT QString buildQueryDatas(ArgsMap argsMap);
}

#endif // CONNECTIONUTILS_HPP
