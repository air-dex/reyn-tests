/// @file testmain.cpp
/// @brief Main function for LibRT tests
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

#include <iostream>
#include "librttests.hpp"

using std::cout;
using std::endl;

/// @fn int main();
/// @brief Main fuction for tests.
/// @return EXIT_SUCCESS
int main() {
	cout << endl << "Testing LibRT" << endl;

	cout << "Test init..." << endl;
	LibRTTests libRTTests;

	cout << "Test execution..." << endl << endl;
	libRTTests.executeTests();

	cout << endl << "Test results : "
		 << libRTTests.getTestResults().toString().toLatin1().data()
		 << '.' << endl;

	return EXIT_SUCCESS;
}
