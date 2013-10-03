/// @file jsonparsertests.cpp
/// @brief Implementation of JSONParserTests
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

#include "jsonparsertests.hpp"

#include <iostream>
#include <QtTest>
#include <QLatin1String>
#include <libRT/JSONParser>
#include "../../testutils.hpp"

using std::cout;
using std::endl;
using LibRT::JSONParser;

// Error message if no JSON was retrieved in files
QString JSONParserTests::NO_JSON_IN_FILE_ERROR = "base/parsers/json_datas/";

// Base folder with JSON datas.
QString JSONParserTests::JSON_DATAS_BASE_DIR = JSONParserTests::trUtf8("Cannot retrieve JSON at %1.");


//////////////////////////
// setUps and tearDowns //
//////////////////////////

// Building goodObject
void JSONParserTests::buildGoodObject() {
	goodObject.insert("lorem", QJsonValue(QString("ipsum")));
	goodObject.insert("hl3_out", QJsonValue(false));

	QJsonArray socialList;
	socialList.append(QJsonValue(QString("facebook")));
	socialList.append(QJsonValue(QString("twitter")));
	socialList.append(QJsonValue(QString("youtube")));

	QJsonObject soclObj;
	soclObj.insert("network", QJsonValue(QString("so.cl")));
	soclObj.insert("owner", QJsonValue(QString("Microsoft")));
	soclObj.insert("known", QJsonValue(false));
	soclObj.insert("known_less_than_identica", QJsonValue(false));
	soclObj.insert("ballmer_years_at_micromou", QJsonValue(33));

	socialList.append(QJsonValue(soclObj));
	socialList.append(QJsonValue(9));

	goodObject.insert("social", QJsonValue(socialList));

	QJsonObject ubuntuObj;
	ubuntuObj.insert("name", QJsonValue(QString("14.04")));
	ubuntuObj.insert("month", QJsonValue(4));
	ubuntuObj.insert("year", QJsonValue(2014));
	ubuntuObj.insert("sabdfl_boss", QJsonValue(true));

	goodObject.insert("ubuntu_next_lts", QJsonValue(ubuntuObj));
}

// Building goodList
void JSONParserTests::buildGoodList() {
	QJsonArray ccList;
	ccList.append(QJsonValue(QString("Mais")));
	ccList.append(QJsonValue(QString("Où")));
	ccList.append(QJsonValue(QString("Et")));
	ccList.append(QJsonValue(QString("Donc")));
	ccList.append(QJsonValue(QString("Or")));
	ccList.append(QJsonValue(QString("Ni")));
	ccList.append(QJsonValue(QString("Car")));

	goodList.append(QJsonValue(ccList));
	goodList.append(QJsonValue(9));
	goodList.append(QJsonValue(QString("lolmia")));
	goodList.append(QJsonValue(true));
	goodList.append(QJsonValue(QJsonObject()));
	goodList.append(QJsonValue(QString("Monado no chikara !")));

	QJsonObject xenobj;
	xenobj.insert("studio", QJsonValue(QString("Monolith")));
	xenobj.insert("xenoblade_chronicles_release_year", QJsonValue(2010));
	xenobj.insert("x_release_year", QJsonValue(2014));

	goodList.append(QJsonValue(xenobj));
}

// Builds JSON references
void JSONParserTests::setUpBeforeClass() {
	buildGoodObject();
	buildGoodList();
}


///////////
// Tests //
///////////

// Testing the JSONParser for JSON objects.
void JSONParserTests::testJSONObjects() {
	JSONParser parser;
	bool parseOK = false;
	QString parseErr = "";
	QJsonValue parseval;

	cout << "\tTest with a good object" << endl;

	QString datapath = NO_JSON_IN_FILE_ERROR + "good_obj_utf8.json";
	QByteArray goodObjUTF8 = findTestData(datapath,
										  JSON_DATAS_BASE_DIR.arg(datapath));

	parseval = parser.parse(goodObjUTF8, &parseOK, &parseErr);

	QVERIFY2(parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is not parsed correctly : %1.").arg(
								 parseErr)));
	QVERIFY2(parseval.isObject(),
			 QTest::toString(JSONParserTests::trUtf8("Parsed results should be a JSON object.")));
	QCOMPARE(parseval.toObject(), goodObject);


	cout << "\tTest with a bad object" << endl;

	datapath = NO_JSON_IN_FILE_ERROR + "bad_obj_utf8.json";
	QByteArray badObjUTF8 = findTestData(datapath,
										 JSON_DATAS_BASE_DIR.arg(datapath));

	parseval = parser.parse(badObjUTF8, &parseOK, &parseErr);

	QVERIFY2(!parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is parsed correctly.")));
	QVERIFY2(!parseErr.isEmpty(),
			 QTest::toString(JSONParserTests::trUtf8("There should be an error message.")));


	cout << "\tTest with an empty object" << endl;

	parseval = parser.parse("{}", &parseOK, &parseErr);

	QVERIFY2(parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is not parsed correctly : %1.").arg(
								 parseErr)));
	QVERIFY2(parseval.isObject(),
			 QTest::toString(JSONParserTests::trUtf8("Empty object should be an object.")));
	QVERIFY2(parseval.toObject().isEmpty(),
			 QTest::toString(JSONParserTests::trUtf8("Empty object should be empty.")));
}

// Testing the JSONParser for JSON arrays.
void JSONParserTests::testJSONArrays() {
	JSONParser parser;
	bool parseOK = false;
	QString parseErr = "";
	QJsonValue parseval;

	cout << "\tTest with a good list" << endl;

	QString datapath = NO_JSON_IN_FILE_ERROR + "good_list_utf8.json";
	QByteArray goodArrayUTF8 = findTestData(datapath,
											JSON_DATAS_BASE_DIR.arg(datapath));

	parseval = parser.parse(goodArrayUTF8, &parseOK, &parseErr);

	QVERIFY2(parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is not parsed correctly : %1.").arg(
								 parseErr)));
	QVERIFY2(parseval.isArray(),
			 QTest::toString(JSONParserTests::trUtf8("Parsed results should be a JSON array.")));
	QCOMPARE(parseval.toArray(), goodList);


	cout << "\tTest with a bad list" << endl;

	datapath = NO_JSON_IN_FILE_ERROR + "bad_list_utf8.json";
	QByteArray badArrayUTF8 = findTestData(datapath,
										   JSON_DATAS_BASE_DIR.arg(datapath));

	parseval = parser.parse(badArrayUTF8, &parseOK, &parseErr);

	QVERIFY2(!parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is parsed correctly.")));
	QVERIFY2(!parseErr.isEmpty(),
			 QTest::toString(JSONParserTests::trUtf8("There should be an error message.")));


	cout << "\tTest with an empty list" << endl;

	parseval = parser.parse("[]", &parseOK, &parseErr);

	QVERIFY2(parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is not parsed correctly : %1.").arg(
								 parseErr)));
	QVERIFY2(parseval.isArray(),
			 QTest::toString(JSONParserTests::trUtf8("Empty array should be an array.")));
	QVERIFY2(parseval.toArray().isEmpty(),
			 QTest::toString(JSONParserTests::trUtf8("Empty array should be empty.")));
}

// Testing different encodings for datas to parse.
void JSONParserTests::testEncodings() {
	JSONParser parser;
	bool parseOK = false;
	QString parseErr = "";
	QJsonValue parseval;

	// Latin-1 JSON datas for the test
	QString datapath = NO_JSON_IN_FILE_ERROR + "good_list_latin1.json";
	QByteArray goodArrayLatin1 = findTestData(datapath,
											  JSON_DATAS_BASE_DIR.arg(datapath));


	cout << "\tWrong array if (Latin-1) datas to parse are not encoded in UTF-8" << endl;

	// Building the array with pure Latin-1 datas
	parseval = parser.parse(goodArrayLatin1,
							&parseOK,
							&parseErr);
	QVERIFY2(parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is not parsed correctly : %1.").arg(
								 parseErr)));
	QVERIFY2(parseval.isArray(),
			 QTest::toString(JSONParserTests::trUtf8("Parsed results should be a JSON array.")));
	QEXPECT_FAIL("", "Comparison should fail because of different encodings", Continue);
	QCOMPARE(parseval.toArray(), goodList);


	cout << "\tRight array if (Latin-1) datas to parse are reencoded in UTF-8" << endl;

	// Building the array with reencoded datas
	parseval = parser.parse(QString::fromLatin1(goodArrayLatin1).toUtf8(),
							&parseOK,
							&parseErr);
	QVERIFY2(parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is not parsed correctly : %1.").arg(
								 parseErr)));
	QVERIFY2(parseval.isArray(),
			 QTest::toString(JSONParserTests::trUtf8("Parsed results should be a JSON array.")));

	QCOMPARE(parseval.toArray(), goodList);
}

// Testing the parser with empty and null datas.
void JSONParserTests::testNope() {
	JSONParser parser;
	bool parseOK = false;
	QString parseErr = "";
	QJsonValue parseval;

	cout << "\tEmpty datas" << endl;

	parseval = parser.parse("", &parseOK, &parseErr);

	QVERIFY2(!parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is parsed correctly.")));
	QVERIFY2(!parseErr.isEmpty(),
			 QTest::toString(JSONParserTests::trUtf8("There should be an error message.")));


	cout << "\tNull datas" << endl;

	parseval = parser.parse(QByteArray(), &parseOK, &parseErr);

	QVERIFY2(!parseOK,
			 QTest::toString(JSONParserTests::trUtf8("JSON text is parsed correctly.")));
	QVERIFY2(!parseErr.isEmpty(),
			 QTest::toString(JSONParserTests::trUtf8("There should be an error message.")));
}
