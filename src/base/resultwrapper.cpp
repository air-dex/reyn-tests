/// @file resultwrapper.cpp
/// @brief Implementation of ResultWrapper
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2011, 2013 Romain Ducher
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

#include "resultwrapper.hpp"

using LibRT::ResultWrapper;
using LibRT::RequestResult;

// Constructor
ResultWrapper::ResultWrapper(QObject * requestSender, RequestResult requestResult) :
	asker(requestSender),
	result(requestResult)
{}

// Default constructor
ResultWrapper::ResultWrapper() :
	asker(0),
	result()
{}

// Method to access to the result
RequestResult ResultWrapper::accessResult(QObject * demanderAdress) {
	return (demanderAdress == asker) ? result : RequestResult();
}
