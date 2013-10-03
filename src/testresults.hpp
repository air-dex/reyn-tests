/// @file testresults.hpp
/// @brief Header of TestResults
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

#ifndef TESTRESULTS_HPP
#define TESTRESULTS_HPP

#include <QString>
#include "reyntests_global.hpp"

namespace ReynTests {
	/// @struct TestResults
	/// @brief Struct containing results of a test, i.e. the number of test which
	/// were successful, failed or were skipped.
	struct REYNTESTS_SHARED_EXPORT TestResults
	{
		/// @fn TestResults();
		/// @brief Constructor
		TestResults();

		/// @fn TestResults & operator +=(const TestResults & otherTest);
		/// @brief Adding results of other tests.
		///
		/// It is useful in a test suite to know the results of the whole suite.
		/// @param otherTest The other test.
		/// @return The object after adding the results of @a otherTest.
		TestResults & operator+=(const TestResults & otherTest);

		/// @fn QString toString() const;
		/// @brief QString version of results.
		/// @return QString displaying how many tests were successful, failed
		/// or were skipped.
		QString toString() const;

		/// @brief Number of tests that were successful.
		int passed;

		/// @brief Number of tests that failed.
		int failed;

		/// @brief Additional fails
		///
		/// This field can be incremented in non main test functions which uses
		/// Qt Test macros
		int bonusFails;

		/// @brief Number of tests that were skipped.
		int skipped;
	};
}

#endif // TESTRESULTS_HPP
