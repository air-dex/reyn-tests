/// @file testsuite.cpp
/// @brief Implementation of TestSuite
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

#include "testsuite.hpp"

// Constructor
TestSuite::TestSuite() :
	TestEntity(),
	QLinkedList<TestEntityPointer>()
{}

// Appends a test entity in the list
TestSuite * TestSuite::appendTestEntity(TestEntity * entity) {
	if (entity != 0) {
		TestEntityPointer newTest(entity);
		this->append(newTest);
	}

	return this;
}

// Exeuting tests
void TestSuite::executeTests() {
	for (TestSuite::const_iterator it = begin(); it != end(); ++it) {
		// Executing entity tests if this last is not NULL.
		TestEntityPointer test = *it;

		if (test) {
			test->executeTests();
			testResults += test->getTestResults();
		}
	}
}
