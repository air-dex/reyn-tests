/// @file requesttokenrequester.cpp
/// @brief Implementation of RequestTokenRequester
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

#include "requesttokenrequester.hpp"

#include <QStringList>
#include "../../../base/parsers/oauthparser.hpp"

using LibRT::NetworkResponse;
using LibRT::OAuthParser;
using LibRT::Twitter::OAuthRequester;
using LibRT::Twitter::RequestTokenRequester;
using LibRT::Twitter::TwitterAuthenticator;

// Constructor
RequestTokenRequester::RequestTokenRequester(const TwitterAuthenticator &authManager,
											 QNetworkAccessManager &netManager) :
	OAuthRequester(POST,
				   REQUEST_TOKEN_URL,
				   authManager,
				   OAUTH_PARSING,
				   netManager,
				   false, true, false)
{}

// Parse the raw results of the request.
QVariant RequestTokenRequester::parseResult(NetworkResponse results,
											bool & parseOK,
											QVariantMap & parsingErrors)
{
	// Key names
	const QString OAUTH_TOKEN_KEY = "oauth_token";
	const QString OAUTH_TOKEN_SECRET_KEY = "oauth_token_secret";
	const QString OAUTH_CALLBACK_CONFIRMED_KEY = "oauth_callback_confirmed";

	// Parsing
	OAuthParser parser;
	QVariantMap resultMap = parser.parse(results.getResponseBody());

	// For treatments
	QString errorMsg = "";
	bool treatmentOK;
	QString treatmentErrorMsg = "";
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

	// oauth_callback_confirmed
	if (resultMap.contains(OAUTH_CALLBACK_CONFIRMED_KEY)) {
		// Rewriting the "oauth_callback_confirmed" parameter as a boolean
		parser.rewriteAsBool(resultMap,
							 OAUTH_CALLBACK_CONFIRMED_KEY,
							 treatmentOK,
							 treatmentErrorMsg);
		parseOK = parseOK && treatmentOK;
		errorMsg.append(treatmentErrorMsg);
	} else {
		// Add it to the missing arguments
		missingArgs.append(OAUTH_CALLBACK_CONFIRMED_KEY);
	}

	parseOK = missingArgs.isEmpty();

	// Listing all the expected parameters
	if (!missingArgs.isEmpty()) {
		errorMsg = RequestTokenRequester::trUtf8("The following parameters were expected: %1.").arg(
					   missingArgs.join(", "));
	}


	// There was a problem while parsing -> fill the parsingErrors map !
	if (!parseOK) {
		parsingErrors.insert("errorMsg", QVariant::fromValue(errorMsg));
	}

	return QVariant::fromValue(resultMap);
}
