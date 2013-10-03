/// @file oauthparser.cpp
/// @brief Implementation of OAuthParser
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

#include "oauthparser.hpp"
#include <QList>
#include <QUrlQuery>

using LibRT::OAuthParser;

// Parsing method
QVariantMap OAuthParser::parse(QByteArray data,
							   bool *, QString *,
							   int *, int *)
{
	QVariantMap res;

	QUrlQuery args(QString::fromLatin1(data));

	QList<QPair<QString, QString> > listArgs = args.queryItems();

	for (QList<QPair<QString, QString> >::iterator it = listArgs.begin();
		 it != listArgs.end();
		 ++it)
	{
		QPair<QString, QString> couple = *it;
		res.insert(couple.first, QVariant::fromValue(couple.second));
	}
	return res;
}

// Rewriting one parameter of the parsed result as a boolean
void OAuthParser::rewriteAsBool(QVariantMap & parsedMap,
								QString parameterName,
								bool & rewriteOK,
								QString & rewriteError)
{
	rewriteOK = parsedMap.contains(parameterName);
	rewriteError = "";

	if (rewriteOK) {
		QString result = parsedMap.value(parameterName).toString();
		bool convertOK = "true" == result || "false" == result;
		rewriteOK = rewriteOK && convertOK;

		if (convertOK) {
			bool booleanValue;

			if ("true" == result) {
				booleanValue = true;
			} else if ("false" == result) {
				booleanValue = false;
			}

			parsedMap.remove(parameterName);
			parsedMap.insert(parameterName, QVariant::fromValue(booleanValue));
		} else {
			// Unexpected value. This is an error.
			rewriteError = QObject::trUtf8("Rewriting as bool: unexpected value '%1' for parameter '%2'.").arg(
							   result,
							   parameterName);
		}
	} else {
		rewriteError = QObject::trUtf8("Rewriting as bool: parameter '%1' expected.").arg(
						   parameterName);
	}
}
