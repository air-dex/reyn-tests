/// @file oauthrequester.cpp
/// @brief Implementation of OAuthRequester
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

#include "oauthrequester.hpp"

using LibRT::ArgsMap;
using LibRT::HTTPRequestType;
using LibRT::NetworkResultType;
using LibRT::Twitter::TwitterAuthenticator;
using LibRT::Twitter::OAuthRequester;

// Cancel button name
QString LibRT::Twitter::DENY_NAME = "cancel";

// Constructor
OAuthRequester::OAuthRequester(HTTPRequestType type,
							   QString url,
							   const TwitterAuthenticator &authManager,
							   NetworkResultType parseErrorType,
							   QNetworkAccessManager &netManager,
							   bool tokenNeeded,
							   bool callbackURLNeeded,
							   bool verifierNeeded) :
	TwitterRequester(type, url, authManager, netManager, parseErrorType),
	oauthTokenNeeded(tokenNeeded),
	oauthCallbackUrlNeeded(callbackURLNeeded),
	oauthVerifierNeeded(verifierNeeded)
{}

// Building the "Authorization" header needed for Twitter requests
QByteArray OAuthRequester::getAuthorizationHeader(ArgsMap getParameters, ArgsMap postParameters) {
	return oauthManager.getAuthorizationHeader(requestType,
											   requestURL,
											   getParameters,
											   postParameters,
											   oauthTokenNeeded,
											   oauthCallbackUrlNeeded,
											   oauthVerifierNeeded);
}
