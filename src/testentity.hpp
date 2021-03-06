/// @file testentity.hpp
/// @brief Header of TestEntity
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

#ifndef TESTENTITY_HPP
#define TESTENTITY_HPP

#include <QObject>
#include "testresults.hpp"

namespace ReynTests {
	/// @class TestEntity
	/// @brief Base class for objects executing tests.
	class REYNTESTS_SHARED_EXPORT TestEntity : public QObject
	{
		Q_OBJECT

		public:
			/// @fn TestEntity();
			/// @brief Constructor
			TestEntity();

			/// @fn TestResults getTestResults() const;
			/// @brief Getting test results
			/// @return testResults
			TestResults getTestResults() const;

			/// @fn virtual void executeTests() const = 0;
			/// @brief Method executing tests.
			/// @return Tests' statistics.
			virtual void executeTests() = 0;

		protected:
			/// @brief Test results
			TestResults testResults;
	};
}


#endif // TESTENTITY_HPP
