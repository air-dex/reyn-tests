/// @file genericparser.hpp
/// @brief Header of GenericParser
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

#ifndef GENERICPARSER_HPP
#define GENERICPARSER_HPP

#include <QByteArray>
#include <QVariantMap>
#include "../librt_global.hpp"

namespace LibRT {
	/// @class GenericParser
	/// @brief Base class for all the parsers.
	/// @param T Type of parsed results
	template <typename T>
	class LIBRTSHARED_EXPORT GenericParser
	{
		public:
			/// @fn virtual QVariantMap parse(QByteArray data,
			///								  bool * parseOK = 0,
			///								  QString * parseError = 0,
			///								  int * lineError = 0,
			///								  int * columnError = 0) = 0;
			/// @brief Method for parsing results
			/// @param data datas to parse
			/// @param parseOK Boolean indicating if the parcing process was successful
			/// @param parseError Error message about a parsing error
			/// @param lineError Line of the error
			/// @param columnError Column of the error
			virtual T parse(QByteArray data,
							bool * parseOK = 0,
							QString * parseError = 0,
							int * lineError = 0,
							int * columnError = 0) = 0;
	};
}

#endif // GENERICPARSER_HPP
