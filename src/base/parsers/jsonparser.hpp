/// @file jsonparser.hpp
/// @brief Header of JSONParser
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

#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP

#include <QJsonValue>
#include "genericparser.hpp"
#include "../librt_global.hpp"

namespace LibRT {
	/// @class JSONParser
	/// @brief Parser for JSON datas.
	class LIBRTSHARED_EXPORT JSONParser : public GenericParser<QJsonValue>
	{
		public:
			/// @fn QJsonValue parse(QByteArray data,
			///						 bool * parseOK = 0,
			///						 QString * parseError = 0,
			///						 int * lineError = 0,
			///						 int * columnError = 0);
			/// @brief Parsing JSON datas
			/// @param data Datas to parse.
			///
			/// JSONParser uses the @c QJsonDocument class to parse datas
			/// contained in @a data. Now @c QJsonDocument parses only UTF-8
			/// encoded texts so the method forces the text to be UTF-8 encoded.
			/// As a consequence, @a data should contain UTF-8 encoded text.
			/// @param parseOK Boolean indicating if the parcing process was successful
			/// @param parseError Error message about a parsing error
			/// @param lineError Line of the error
			/// @param columnError Column of the error. Unused.
			QJsonValue parse(QByteArray data,
							 bool * parseOK = 0,
							 QString * parseError = 0,
							 int * lineError = 0,
							 int * columnError = 0);
	};
}

#endif // JSONPARSER_HPP
