/// @file connectionutils.cpp
/// @brief Implementation of the useful methods declared in connectionutils.hpp.
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

#include "connectionutils.hpp"
#include <QCryptographicHash>
#include <QVariant>
#include <QMapIterator>
#include <QMetaProperty>
#include <QJsonDocument>
#include <QUrl>
#include <QUrlQuery>

using LibRT::HTTPRequestType;
using LibRT::ArgsMap;

///////////////////////
// String convertion //
///////////////////////

// Converting a RequestType into a QString
QString LibRT::requestTypeToString(HTTPRequestType type) {
	switch (type) {
		case GET:
			return "GET";
		case POST:
			return "POST";
		default:
			return "";
	}
}

// Converting a bool into a QString
QString LibRT::boolInString(bool b) {
	return b ? "true" : "false";
}


//////////////////
// Miscanellous //
//////////////////

// Exclusive OR
bool LibRT::ouBien(bool a, bool b) {
	return  (a && !b) || (!a && b);
}

// Formatting parameters in the Authorization header
QString LibRT::formatParam(QString name, QString value, bool putDoubleQuotes) {
	QString res = "";
	QByteArray percentEncoded;

	// Percent encoding the name
	percentEncoded = QUrl::toPercentEncoding(name);
	res.append(percentEncoded);

	res.append('=');
	if (putDoubleQuotes) {
		res.append('"');
	}

	// Percent encoding the value
	percentEncoded = QUrl::toPercentEncoding(value);
	res.append(percentEncoded);

	if (putDoubleQuotes) {
		res.append('"');
	}

	return res;
}

// Building the string that will contain all the arguments
// of the given ArgsMap just like in an URL.
QString LibRT::buildQueryDatas(ArgsMap argsMap) {
	QUrlQuery query;

	// Writing the arguments
	for (ArgsMap::iterator argsIterator = argsMap.begin();
		 argsIterator != argsMap.end();
		 ++argsIterator) {
		// Getting the value of the argument
		QString argValue = argsIterator.value();

		if (argValue.isEmpty()) {
			continue;
		}

		// Getting the name of the argument
		QString argName = argsIterator.key();

		// Append the argument in the argument string
		query.addQueryItem(argName, argValue);
	}

	return query.query();
}
