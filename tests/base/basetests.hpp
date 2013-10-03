/// @file basetests.hpp
/// @brief Header of BaseTests
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

#ifndef BASETESTS_HPP
#define BASETESTS_HPP

#include "../testsuite.hpp"

/// @class BaseTests
/// @brief Class with all the tests related to the base LibRT cases.
///
/// It is a test suite containing test for :<ul>
/// <li>Parsers (ParsersTests test suite).</li>
/// <li>HTML arg builders tests (TODO)</li>
/// <li>utils tests (TODO)</li>
/// <li>Communicators tests (TODO)</li>
/// <li>Requesters tests (TODO)</li>
/// <li>Calls tests (TODO)</li>
/// <li>Tests for other entities (TODO ?)</li>
/// </ul>
class BaseTests : public TestSuite
{
	Q_OBJECT

	public:
		/// @fn BaseTests();
		/// @brief Building the test suite.
		BaseTests();
};

#endif // BASETESTS_HPP
