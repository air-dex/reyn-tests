/// @file xmlparser.hpp
/// @brief Header of XMLParser
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2012, 2013 Romain Ducher
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

#ifndef XMLPARSER_HPP
#define XMLPARSER_HPP

#include <QDomElement>
#include "genericparser.hpp"
#include "../librt_global.hpp"

namespace LibRT {
	/// @class XMLParser
	/// @brief Parsing an XML document.
	class LIBRTSHARED_EXPORT XMLParser : public GenericParser<QDomElement>
	{
		public:
			/// @fn QDomElement parse(QByteArray data,
			///						  bool * parseOK = 0,
			///						  QString * parseError = 0,
			///						  int * lineError = 0,
			///						  int * columnError = 0);
			/// @brief Method for parsing results
			/// @param data datas to parse
			/// @param parseOK Boolean indicating if the parcing process was successful
			/// @param parseError Error message about a parsing error
			/// @param lineError Line of the error
			/// @param columnError Column of the error
			QDomElement parse(QByteArray data,
							  bool * parseOK = 0,
							  QString * parseError = 0,
							  int * lineError = 0,
							  int * columnError = 0);
	};
}

#endif // XMLPARSER_HPP
