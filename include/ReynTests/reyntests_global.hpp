/// @file reyntests_global.hpp
/// @brief Definition of REYNTESTS_SHARED_EXPORT for library export.
/// @author Romain Ducher
///
/// @copyright 2013 Romain Ducher
///
/// @section LICENSE
///
/// This file is part of Reyn Tests.
///
/// Reyn Tests is free software: you can redistribute it and/or modify it under
/// the terms of the GNU Lesser General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// Reyn Tests is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
/// for more details.
///
/// You should have received a copy of the GNU Lesser General Public License
/// along with Reyn Tests. If not, see <http://www.gnu.org/licenses/>.

#ifndef REYNTESTS_GLOBAL_HPP
#define REYNTESTS_GLOBAL_HPP

#include <QtGlobal>

#ifdef REYNTESTS_LIBRARY
#define REYNTESTS_SHARED_EXPORT Q_DECL_EXPORT
#else
#define REYNTESTS_SHARED_EXPORT Q_DECL_IMPORT
#endif

/// @namespace ReynTests
/// @brief General namespace for stuff related to Reyn Tests.
namespace ReynTests {}

#endif // REYNTESTS_GLOBAL_HPP
