/// @file testutils.hpp
/// @brief Declaration of utilities for tests.
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

#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP

#include <QString>
#include "reyntests_global.hpp"

namespace ReynTests {
	/// @fn REYNTESTS_SHARED_EXPORT QByteArray findTestData(const QString namefile,
	///														const QString errMsg);
	/// @brief Finding datas in a file for a test.
	///
	/// The function performs checks on what it finds so the test will fail
	/// if no datas are retrieved.
	/// @param namefile Name of the file
	/// @param errMsg Error message if datas are unexpectedly empty.
	/// @return The file content.
	REYNTESTS_SHARED_EXPORT QByteArray findTestData(const QString namefile,
													const QString errMsg);
}


#endif // TESTUTILS_HPP
