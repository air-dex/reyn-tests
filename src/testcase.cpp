/// @file testcase.cpp
/// @brief Implementation of TestCase
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

#include "testcase.hpp"
#include <iostream>
#include <QtTest>

using std::cout;
using std::endl;
using ReynTests::TestCase;
using ReynTests::TestEntity;

// Constructor
ReynTests::TestCase::TestCase() :
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
	FAIL_TEST()
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
	FAIL_TEST()
}

// cleanup(); for derived classes.
void TestCase::tearDown() {}

// Cleans up the whole test case
void TestCase::cleanupTestCase() {
	nbTests++;
	tearDownAfterClass();
	FAIL_TEST()

	// How many tests were successful ?
	testResults.passed = nbTests - testResults.failed - testResults.skipped;
	cout << endl;
}

// cleanupTestCase(); for derived classes.
void TestCase::tearDownAfterClass() {}
