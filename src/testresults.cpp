/// @file testresults.cpp
/// @brief Implementation of TestResults
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

#include "testresults.hpp"

#include <QObject>

// Constructor
TestResults::TestResults() :
	passed(0),
	failed(0),
	skipped(0)
{}

// Adding results of other tests.
TestResults & TestResults::operator+=(const TestResults & otherTest) {
	passed += otherTest.passed;
	failed += otherTest.failed;
	skipped += otherTest.skipped;

	return *this;
}

// QString version of results.
QString TestResults::toString() {
	return QObject::trUtf8("%1 passed, %2 failed and %3 skipped").arg(
				QString::number(passed),
				QString::number(failed),
				QString::number(skipped)
			);
}
