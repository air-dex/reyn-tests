/// @file testutils.cpp
/// @brief Implementation of utilities for tests.
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

#include "testutils.hpp"

#include <QtTest>
#include <QFile>

// Finding datas in a file for a test.
QByteArray findTestData(const QString namefile, const QString errMsg) {
	QByteArray testDatas = "";
	datatestFinder(testDatas, namefile, errMsg);
	return testDatas;
}

// Internal functions
namespace {
	/// @fn void datatestFinder(QByteArray & testDatas,
	///							const QString namefile,
	///							const QString errMsg);
	/// @brief Finding datas in a file for a test.
	///
	/// It has to return @c void because of the @c QVERIFY macro which performs
	/// checks on retrieved datas. That's why the first parameter is the result.
	/// @param testDatas Datas retrieved by the Qt Test's @c QFINDTESTDATA macro.
	/// @param namefile Name of the file.
	/// @param errMsg Error message if datas are unexpectedly empty.
	void datatestFinder(QByteArray & testDatas, const QString namefile, const QString errMsg) {
		QString nameTestfile = QFINDTESTDATA(namefile);

		QVERIFY2(!nameTestfile.isEmpty(),
				 QTest::toString(QObject::trUtf8("Cannot retrieve a test file at '%1'.")
								 .arg(namefile)
								 ));

		QFile file(nameTestfile);

		if (file.open(QIODevice::ReadOnly)) {
			testDatas = file.readAll();
			file.close();
		} else {
			QFAIL(QTest::toString(errMsg));
		}
	}
}
