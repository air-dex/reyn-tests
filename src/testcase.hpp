/// @file testcase.hpp
/// @brief Header of TestCase
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

#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include "testentity.hpp"
#include "testutils.hpp"

/// @def FAIL_TEST()
/// @brief Shorcut for FAILED_TEST with the value @c TestCase::testResults.
#define FAIL_TEST() FAILED_TEST(testResults)

/// @def RT_SKIP(description, testres)
/// @brief Wrapping macro for skipping a test.
///
/// Wraps the QSKIP Qt Test macro in order to handle its result (a skipped test).
/// @param description Text explaining why the test is skipped.
/// @param testres Test results. <strong>Its type has to be TestResults.</strong>
#define RT_SKIP(description, testres) \
	testres.skipped++; \
	QSKIP(description)

namespace ReynTests {
	/// @class TestCase
	/// @brief Base class for all unit test classes.
	///
	/// Its <code>executeTests();</code> method execute all the unit tests coded
	/// in this class, using the <code>QTest::qExec();</code> function on itself.
	class REYNTESTS_SHARED_EXPORT TestCase : public TestEntity
	{
		Q_OBJECT

		public:
			/// @fn TestCase();
			/// @brief Constructor
			TestCase();

			/// @fn virtual void executeTests() const;
			/// @brief Executing all the tests of this TestCase.
			/// @return Tests' statistics.
			virtual void executeTests();

		protected:
			/// @brief Number of tests.
			uint nbTests;


		//////////////////////////
		// setUps and tearDowns //
		//////////////////////////

		private slots:
			// General template

			/// @fn void initTestCase();
			/// @brief Inits a test.
			///
			/// Increment nbTests and then executes @c setUpBeforeClass();
			void initTestCase();

			/// @fn void init();
			/// @brief Inits a test.
			///
			/// Increment nbTests and then executes @c setUp();
			void init();

			/// @fn void cleanup();
			/// @brief After a test
			///
			/// Increments the number of failures (if the test failed, of course)
			/// and then executes @c tearDown();
			void cleanup();

			/// @fn void cleanupTestCase();
			/// @brief Cleans up the whole test case.
			///
			/// Increments nbTests and the number of failures (if the test
			/// failed, of course) and then executes @c tearDownAfterClass();
			void cleanupTestCase();

		protected:
			// For derived classes

			/// @fn virtual void setUp();
			/// @brief @c initTestCase(); for derived classes.
			virtual void setUpBeforeClass();

			/// @fn virtual void setUp();
			/// @brief @c init(); for derived classes.
			virtual void setUp();

			/// @fn virtual void tearDown();
			/// @brief @c cleanup(); for derived classes.
			virtual void tearDown();

			/// @fn virtual void tearDownAfterClass();
			/// @brief @c cleanupTestCase(); for derived classes.
			virtual void tearDownAfterClass();
	};
}

#endif // TESTCASE_HPP
