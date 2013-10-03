/// @file librt_global.hpp
/// @brief Definition of LIBRTSHARED_EXPORT for library export.
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

#ifndef LIBRT_GLOBAL_HPP
#define LIBRT_GLOBAL_HPP

#include <QtGlobal>

#ifdef LIBRT_LIBRARY
#define LIBRTSHARED_EXPORT Q_DECL_EXPORT
#else
#define LIBRTSHARED_EXPORT Q_DECL_IMPORT
#endif

/// @namespace LibRT
/// @brief General namespace for stuff related to libRT.
namespace LibRT {}

#endif // LIBRT_GLOBAL_HPP
