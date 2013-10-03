/// @file testutils.hpp
/// @brief Declaration of utilities for tests.
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

#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP

#include <QString>

/// @fn QByteArray findTestData(const QString namefile, const QString errMsg);
/// @brief Finding datas in a file for a test.
///
/// The function performs checks on what it finds so the test will fail
/// if no datas are retrieved.
/// @param namefile Name of the file
/// @param errMsg Error message if datas are unexpectedly empty.
/// @return The file content.
QByteArray findTestData(const QString namefile, const QString errMsg);

#endif // TESTUTILS_HPP
