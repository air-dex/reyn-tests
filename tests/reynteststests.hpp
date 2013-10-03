/// @file reynteststests.hpp
/// @brief Header of ReynTestsTests.
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

#ifndef REYNTESTSTESTS_HPP
#define REYNTESTSTESTS_HPP

#include <QObject>

/// @class ReynTestsTests
/// @brief Class for Reyn Tests' tests.
///
/// Unfortunately this class cannot use Reyn Tests to test the library since
/// Reyn Tests  @b IS what this class is testing.
class ReynTestsTests : public QObject
{
	Q_OBJECT

	private slots:
		/// @fn void utilsTest();
		/// @brief Announcing which test is executed.
		void init();

		/// @fn void utilsTest();
		/// @brief Tests for test utilities.
		void utilsTest();

		/// @fn void resultsTest();
		/// @brief Tests for TestResult.
		void resultsTest();

		/// @fn void caseTest();
		/// @brief Tests for TestCase.
		void caseTest();

		/// @fn void suiteTest();
		/// @brief Tests for TestSuite.
		void suiteTest();
};

#endif // REYNTESTSTESTS_HPP
