/// @file accesstokenrequester.cpp
/// @brief Implementation of AccessTokenRequester
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

#include "accesstokenrequester.hpp"

#include <QStringList>
#include "../../../base/parsers/oauthparser.hpp"

using LibRT::OAuthParser;
using LibRT::ArgsMap;
using LibRT::NetworkResponse;
using LibRT::Twitter::OAuthRequester;
using LibRT::Twitter::AccessTokenRequester;
using LibRT::Twitter::TwitterAuthenticator;

// Constructor
AccessTokenRequester::AccessTokenRequester(const TwitterAuthenticator &authManager,
										   QNetworkAccessManager &netManager) :
	OAuthRequester(POST,
				   ACCESS_TOKEN_URL,
				   authManager,
				   OAUTH_PARSING,
				   netManager,
				   true, false, true)
{}

// Building POST Parameters
ArgsMap AccessTokenRequester::buildPOSTParameters() {
	ArgsMap postParameters;

	postParameters.insert("oauth_verifier",
						  QString::fromLatin1(oauthManager.getVerifier()));

	return postParameters;
}

// Parse the raw results of the request.
QVariant AccessTokenRequester::parseResult(NetworkResponse results,
										   bool & parseOK,
										   QVariantMap & parsingErrors)
{
	// Key names
	const QString OAUTH_TOKEN_KEY = "oauth_token";
	const QString OAUTH_TOKEN_SECRET_KEY = "oauth_token_secret";
	const QString USER_ID_KEY = "user_id";
	const QString SCREEN_NAME_KEY = "screen_name";

	// Parsing
	OAuthParser parser;
	QVariantMap resultMap = parser.parse(results.getResponseBody());

	// For treatments
	QStringList missingArgs;

	// oauth_token
	if (!resultMap.contains(OAUTH_TOKEN_KEY)) {
		// Add it to the missing arguments
		missingArgs.append(OAUTH_TOKEN_KEY);
	}

	// oauth_token_secret
	if (!resultMap.contains(OAUTH_TOKEN_SECRET_KEY)) {
		// Add it to the missing arguments
		missingArgs.append(OAUTH_TOKEN_SECRET_KEY);
	}

	// user_id
	if (!resultMap.contains(USER_ID_KEY)) {
		// Add it to the missing arguments
		missingArgs.append(USER_ID_KEY);
	}

	// screen_name
	if (!resultMap.contains(SCREEN_NAME_KEY)) {
		// Add it to the missing arguments
		missingArgs.append(SCREEN_NAME_KEY);
	}

	parseOK = missingArgs.isEmpty();

	// Listing all the expected parameters
	if (!missingArgs.isEmpty()) {
		QString errorMsg = AccessTokenRequester::trUtf8("The following parameters were expected: %1.").arg(
							   missingArgs.join(", "));

		// Fill the parsingErrors map !
		parsingErrors.insert("errorMsg", QVariant::fromValue(errorMsg));
	}

	return QVariant::fromValue(resultMap);
}
