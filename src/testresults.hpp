/// @file testresults.hpp
/// @brief Header of TestResults
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

#ifndef TESTRESULTS_HPP
#define TESTRESULTS_HPP

#include <QString>

/// @struct TestResults
/// @brief Struct containing results of a test, i.e. the number of test which
/// were successful, failed or were skipped.
struct TestResults
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

	/// @fn QString toString();
	/// @brief QString version of results.
	/// @return QString displaying how many tests were successful, failed
	/// or were skipped.
	QString toString();

	/// @brief Number of tests that were successful.
	uint passed;

	/// @brief Number of tests that failed.
	uint failed;

	/// @brief Number of tests that were skipped.
	uint skipped;
};

#endif // TESTRESULTS_HPP
