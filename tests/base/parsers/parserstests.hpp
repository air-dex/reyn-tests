/// @file parserstests.hpp
/// @brief Header of ParsersTests
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

#ifndef PARSERSTESTS_HPP
#define PARSERSTESTS_HPP

#include "../../testsuite.hpp"

/// @class ParsersTests
/// @brief Tests for parsers.
///
/// It is a test suite containing test cases for parsers :<ul>
/// <li>JSON parsers (JSONParserTests)</li>
/// <li>XML parsers (TODO)</li>
/// <li>HTML parsers (TODO)</li>
/// <li>Query parsers (OAuthParsers) (TODO)</li>
/// </ul>
class ParsersTests : public TestSuite
{
	Q_OBJECT

	public:
		/// @fn ParsersTests();
		/// @brief Building the test suite.
		ParsersTests();
};

#endif // PARSERSTESTS_HPP
