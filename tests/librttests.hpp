/// @file librttests.hpp
/// @brief Header of LibRTTests
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

#ifndef LIBRTTESTS_HPP
#define LIBRTTESTS_HPP

#include "testsuite.hpp"

/// @class LibRTTests
/// @brief Main class for LibRT tests.
///
/// It is a test suite made of tests suites for :<ul>
/// <li>Base classes for supported services (BaseTests test suite).</li>
/// <li>Services supported by LibRT. Each service has got its own test
/// suite.</li>
/// </ul>
class LibRTTests : public TestSuite
{
	Q_OBJECT

	public:
		/// @fn LibRTTests();
		/// @brief Building the test suite.
		LibRTTests();
};

#endif // LIBRTTESTS_HPP
