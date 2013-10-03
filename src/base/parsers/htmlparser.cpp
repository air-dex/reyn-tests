/// @file htmlparser.cpp
/// @brief Implementation of HTMLParser
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

#include "htmlparser.hpp"
#include <QWebFrame>
#include <QWebPage>

using LibRT::HTMLParser;

// Parsing results
QWebElement HTMLParser::parse(QByteArray data,
							  bool * parseOK,
							  QString * parseError,
							  int *, int *)
{
	QWebPage webPage;
	QWebFrame * frame = webPage.mainFrame();

	if (parseOK) {
		*parseOK = frame != 0;
	}

	if (frame) {
		frame->setHtml(QString::fromUtf8(data.data()));
		if (parseError) {
			*parseError = "";
		}
		return frame->documentElement();
	} else {
		if (parseError) {
			*parseError = QObject::trUtf8("No HTML parser available.");
		}
		return QWebElement();
	}
}
