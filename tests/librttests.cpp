/// @file librttests.cpp
/// @brief Implementation of LibRTTests
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

#include "librttests.hpp"

#include <QtTest>
#include "base/basetests.hpp"

// Constructor
LibRTTests::LibRTTests() :
	TestSuite()
{
	// LibRT base classes
	this->appendTestEntity(new BaseTests);

	// TODO: Tests for LibRT's Twitter support.
	// TODO: Tests for LibRT's TwitLonger support.
	// TODO: Tests for LibRT's PEBKAC.fr support.
}
