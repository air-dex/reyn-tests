/// @file pebkacauthenticator.cpp
/// @brief Implementation of PebkacAuthenticator
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

#include "pebkacauthenticator.hpp"
#include "pebkacconstants.hpp"

using LibRT::NetworkResultType;

// Constructor
PEBKAC::PebkacAuthenticator::PebkacAuthenticator() :
	LibRT::APIKeyAuthenticator(),
	userAgent(""),
	outputFormat(INVALID_RESULT)
{}

// Destructor
PEBKAC::PebkacAuthenticator::~PebkacAuthenticator() {}


/////////////////////////
// Getters and setters //
/////////////////////////

// User Agent
QByteArray PEBKAC::PebkacAuthenticator::getUserAgent() const {
	return userAgent;
}

void PEBKAC::PebkacAuthenticator::setUserAgent(const QByteArray &newAgent) {
	userAgent = newAgent;
}

// Output Format
NetworkResultType PEBKAC::PebkacAuthenticator::getOutputFormat() const {
	return outputFormat;
}

void PEBKAC::PebkacAuthenticator::setOutputFormat(const NetworkResultType &newFormat)
{
	outputFormat = newFormat;
}