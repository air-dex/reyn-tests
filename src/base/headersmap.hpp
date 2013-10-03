/// @file headersmap.hpp
/// @brief Header with the definition of ArgsMap and HeadersMap.
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

#ifndef HEADERSMAP_HPP
#define HEADERSMAP_HPP

#include <QByteArray>
#include <QMap>
#include <QString>
#include "librt_global.hpp"

namespace LibRT {
	/// @typedef QMap<QByteArray, QByteArray> ArgsMap
	/// @brief Convinience to designate QMaps that contains GET and POST arguments
	typedef QMap<QString, QString> /*LIBRTSHARED_EXPORT*/ ArgsMap;

	/// @typedef QMap<QString, QString> HeadersMap
	/// @brief Convinience to designate QMaps that contains HTTP headers
	typedef QMap<QByteArray, QByteArray> /*LIBRTSHARED_EXPORT*/ HeadersMap;
}


#endif // HEADERSMAP_HPP
