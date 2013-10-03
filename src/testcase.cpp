/// @file testcase.cpp
/// @brief Implementation of TestCase
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

#include "testcase.hpp"
#include <QtTest>

#include <iostream>
using std::cout;
using std::endl;

/// @def FAILED_TEST()
/// @brief Macros testing if a test failed. It increments the fail counter
/// if necessary.
#define FAILED_TEST() \
	if (QTest::currentTestFailed()) { \
		testResults.failed++; \
	}

// Constructor
TestCase::TestCase() :
	TestEntity(),
	nbTests(0)
{}

// Exeuting tests
void TestCase::executeTests() {
	QTest::qExec((QObject *) this);
}

// Inits the whole test case
void TestCase::initTestCase() {
	nbTests++;
	setUpBeforeClass();
	FAILED_TEST()
}

// initTestCase(); for derived classes.
void TestCase::setUpBeforeClass() {}

// Inits a test
void TestCase::init() {
	cout << endl << QTest::currentTestFunction() << " test :" << endl;
	nbTests++;
	setUp();
}

// init(); for derived classes.
void TestCase::setUp() {}

// Cleans up a test
void TestCase::cleanup() {
	tearDown();
	FAILED_TEST()
}

// cleanup(); for derived classes.
void TestCase::tearDown() {}

// Cleans up the whole test case
void TestCase::cleanupTestCase() {
	nbTests++;
	tearDownAfterClass();
	FAILED_TEST()

	// How many tests were successful ?
	testResults.passed = nbTests - testResults.failed - testResults.skipped;
	cout << endl;
}

// cleanupTestCase(); for derived classes.
void TestCase::tearDownAfterClass() {}
