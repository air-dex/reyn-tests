/// @file reynteststests.cpp
/// @brief Implementation of ReynTestsTests.
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

#include "reynteststests.hpp"

#include <iostream>
#include <QtTest>
#include <ReynTests/TestUtils>
#include <ReynTests/TestResults>
#include <ReynTests/TestCase>

using std::cout;
using std::endl;
using ReynTests::TestResults;
using ReynTests::TestCase;
//using ReynTests::;
//using ReynTests::;

// Announcing which test is executed.
void ReynTestsTests::init() {
	cout << endl << QTest::currentTestFunction() << " test :" << endl;
}

// Test utilities
void ReynTestsTests::utilsTest() {
	cout << "\tTest QByteArray findTestData(const QString &, const QString &);"
		 << endl;
	using ReynTests::findTestData;

	cout << "\t\tTest with a right file which contains datas :" << endl;
	QByteArray fileDatas = findTestData("../tests/datas/testfile.txt",
										"Cannot find an existing file");
	QCOMPARE(fileDatas.data(), "Raindrops!\n");

	cout << "\t\tTest with a wrong file :" << endl;
	QEXPECT_FAIL("",
				 "It should not find something which does not exist.",
				 Continue);
	fileDatas = findTestData("reyn.txt", "Something unknown was not found.");
}

// TestResult
void ReynTestsTests::resultsTest() {
	cout << "\tTesting TestResults & operator+=(const TestResults &); :" << endl;

	TestResults t1;
	t1.passed = 5;
	t1.failed = 2;
	t1.skipped = 1;

	TestResults t2;
	t2.passed = 3;
	t2.failed = 4;
	t2.skipped = 2;

	t1 += t2;
	QCOMPARE(int(t1.passed), 8);
	QCOMPARE(int(t1.failed), 6);
	QCOMPARE(int(t1.skipped), 3);


	cout << "\tTesting QString toString() const; :" << endl;

	QCOMPARE(t2.toString(), "3 passed, 4 failed and 2 skipped");
}

// TestCase
void ReynTestsTests::caseTest() {
	QSKIP("Cannot test because it is not possible to call QTest::qExec(); in a QTest::qExec(); function.");
}

// TestSuite
void ReynTestsTests::suiteTest() {
	QSKIP("Cannot test because it is not possible to call QTest::qExec(); in a QTest::qExec(); function.");
}
