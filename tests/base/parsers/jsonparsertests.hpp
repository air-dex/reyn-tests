/// @file jsonparsertests.hpp
/// @brief Header of JSONParserTests
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

#ifndef JSONPARSERTESTS_HPP
#define JSONPARSERTESTS_HPP

#include <QJsonArray>
#include <QJsonObject>
#include "../../testcase.hpp"

/// @class JSONParserTests
/// @brief Tests for LibRT::JSONParser
class JSONParserTests : public TestCase
{
	Q_OBJECT

	protected:
		/// @brief Error message if no JSON was retrieved in files
		static QString NO_JSON_IN_FILE_ERROR;

		/// @brief Base folder with JSON datas.
		static QString JSON_DATAS_BASE_DIR;


		//////////////////////////
		// setUps and tearDowns //
		//////////////////////////

		/// @fn QJsonObject buildGoodObject() const;
		/// @brief Building a valid JSON object.
		///
		/// It builds the valid JSON object as defined in "good_obj_*.json"
		/// files. It will be compared to JSON objects built by the JSONParser.
		/// @return The "Good Object" as a QJsonObject
		void buildGoodObject();

		/// @brief The "Good Object"
		QJsonObject goodObject;

		/// @fn QJsonArray buildGoodList() const;
		/// @brief Building a valid JSON list.
		///
		/// It builds the valid JSON list as defined in "good_list_*.json"
		/// files. It will be compared to JSON arrays built by the JSONParser.
		/// @return The "Good List" as a QJsonArray
		void buildGoodList();

		/// @brief The "Good List"
		QJsonArray goodList;

		/// @fn virtual void setUpBeforeClass();
		/// @brief Builds reference JSON entities.
		virtual void setUpBeforeClass();


	///////////
	// Tests //
	///////////

	private slots:
		/// @fn void testJSONObjects();
		/// @brief Testing the JSONParser for JSON objects.
		void testJSONObjects();

		/// @fn void testJSONArrays();
		/// @brief Testing the JSONParser for JSON arrays.
		void testJSONArrays();

		/// @fn void testEncodings();
		/// @brief Testing different encodings for datas to parse.
		void testEncodings();

		/// @fn void testNope();
		/// @brief Testing the parser with empty and null datas.
		void testNope();
};

#endif // JSONPARSERTESTS_HPP
