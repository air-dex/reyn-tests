/// @file testsuite.hpp
/// @brief Header of TestSuite
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

#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#include <QLinkedList>
#include <QSharedPointer>
#include "testentity.hpp"

/// @typedef typedef QSharedPointer<TestEntity> TestEntityPointer;
/// @brief Typedef for smart pointers on test entities.
typedef QSharedPointer<TestEntity> TestEntityPointer;

/// @class TestSuite
/// @brief Base class for tests suites. It contains a list of test entities
/// (test cases or test suites) that the class will have to execute tests.
///
/// The suite stores test entities in an array of smart pointers on the test
/// entities. As a consequence, the test entities will be "smart destroyed"
/// when the test suite is destroyed. ;-)
class TestSuite : public TestEntity, protected QLinkedList<TestEntityPointer>
{
	Q_OBJECT

	public:
		/// @fn TestSuite();
		/// @brief Constructor
		TestSuite();

		/// @fn virtual void executeTests() const;
		/// @brief Executing all the tests of this TestSuite.
		/// @return Tests' statistics.
		virtual void executeTests();

		/// @fn TestSuite * appendTestEntity(TestEntity * entity);
		/// @brief Appends a test entity in the list
		/// @param entity The pointer on the test entity. The TestEntity
		/// will not be appended if @a entity is NULL.
		/// @return It returns the list in order to be able to move on
		/// calls to this method.
		TestSuite * appendTestEntity(TestEntity * entity);
};

#endif // TESTSUITE_HPP
