/// @file pebkacrequester.hpp
/// @brief Header of PebkacRequester
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

#ifndef PEBKACREQUESTER_HPP
#define PEBKACREQUESTER_HPP

#include <QDomElement>
#include <QString>
#include <QVariantMap>
#include "../../base/librt_global.hpp"
#include "../../base/requests/genericrequester.hpp"
#include "../pebkacauthenticator.hpp"

namespace LibRT {
	namespace Pebkac {

		/// @class PebkacRequester
		/// @brief Base class for PEBKAC.fr requesters
		class PebkacRequester : public GenericRequester
		{
			Q_OBJECT

			public:
				/// @fn PebkacRequester(HTTPRequestType type,
				///						QString url,
				///						const PebkacAuthenticator & authPebkac,
				///						QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param type Type of the request (GET ou POST).
				/// @param url URL called by the requester
				/// @param authPebkac Authentication datas for PEBKAC.fr
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				PebkacRequester(HTTPRequestType type,
								QString url,
								const PebkacAuthenticator & authPebkac,
								QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

				/// @fn ~PebkacRequester();
				/// @brief Destructor
				~PebkacRequester();

			public slots:

			protected:
				/// @brief Authentication datas for the PEBKAC.fr API.
				const PebkacAuthenticator & pebkacAuth;

				/// @brief Pattern for building default arguments. Build with
				/// the GET arguments ArgsMap.
				QString pattern;

				//////////////////////////////////
				// GenericRequester overridings //
				//////////////////////////////////

				/// @fn virtual ArgsMap buildGETParameters();
				/// @brief Virtual method building GET Parameters and
				/// the pattern they will fill.
				/// @return GET parameters that will be passed to the Communicator.
				virtual ArgsMap buildGETParameters();

				/// @fn virtual GetArgs buildGETArgs();
				/// @brief Building the GET arguments builder.
				///
				/// The GenericRequester default builder build arguments like
				/// URL queries.
				/// @return GET parameters that will be passed to the Communicator.
				virtual GetArgs buildGETArgs();

				/// @fn virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
				///											ArgsMap postParameters);
				/// @brief Virtual method building headers
				/// @param getParameters GET parameters for the Communicator.
				/// @param postParameters POST parameters for the Communicator.
				/// @return HTTP headers that will be passed to the Communicator.
				virtual HeadersMap buildHTTPHeaders(ArgsMap getParameters,
													ArgsMap postParameters);

				/// @fn virtual void treatResults(NetworkResponse netResponse);
				/// @brief Treating the result, when the Communicator has just
				/// finished its work.
				/// @param netResponse Struct with response elements
				virtual void do_treatResults(NetworkResponse netResponse);

				/// @fn virtual QVariant parseResult(NetworkResponse results,
				///									 bool & parseOK,
				///									 QVariantMap & parsingErrors) = 0;
				/// @brief Method that will parse the raw results of the request.
				/// @param results Results to parse. Most of the time the method only
				/// uses the responseBody field.
				/// @param parseOK Boolean whose value will be set to true if there was
				/// no problem while parsing, false otherwise.
				/// @param parsingErrors QVariantMap that may contain information about
				/// errors that may occur while parsing.
				/// @return Parsed results
				virtual QVariant parseResult(NetworkResponse results,
											 bool & parseOK,
											 QVariantMap & parsingErrors);

				/// @fn QVariantMap parseItem(QDomElement item) const;
				/// @brief Converting a "item" XML element into a QVariantMap.
				///
				/// In the PEBKAC API, "item" are used to be written like this :
				/// <code>
				/// &lt;item&gt;
				///		&lt;name_1&gt;val_1&lt;/name_1&gt;
				/// 	&lt;name_2&gt;val_2&lt;/name_2&gt;
				/// 	...
				/// 	&lt;name_n&gt;val_n&lt;/name_n&gt;
				/// &lt;/item&gt;
				/// </code>
				///
				/// This method will put this item in a QVariantMap where keys are
				/// the <code>name_i</code> XML tag names and the values are the
				/// corresponding <code>val_i</code> values (1 &le; i &le; n).
				/// @param item The "item" XML element
				/// @return The corresponding QVariantMap
				QVariantMap parseItem(QDomElement item) const;

				/// @fn virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
				///														NetworkResponse netResponse);
				/// @brief Treating parsed results
				/// @param parsedResults Parsed results to analyse in order to retrieve
				/// service errors.
				/// @param netResponse Other network response elements, if needed.
				/// @return The list of service errors
				virtual QList<ResponseInfos> treatServiceErrors(QVariant parsedResults,
																NetworkResponse netResponse);


				/////////////////////////
				// Error case handling //
				/////////////////////////

				/// @brief Regex pattern for error responses returned by the API.
				static QString ERROR_REGEX_PATTERN;

				/// @fn static QString buildErrorRegexPattern();
				/// @brief Building ERROR_REGEX_PATTERN static attribute
				/// @return <code>^Error\\s\\[AEx(?&lt;code&gt;999|00\\d)\\]\\s\0072\\s(?&lt;description&gt;*)$</code>
				static QString buildErrorRegexPattern();

				/// @fn bool responseIsError(const QByteArray rawResponse) const;
				/// @brief Method for determining if the respnse given by the
				/// PEBKAC.fr API is successfull.
				///
				/// The response is considered as successful if @a rawResponse does
				/// <strong> not</strong> match the ERROR_REGEX_PATTERN regex pattern.
				/// @param rawResponse The response (given by the PEBKAC.fr API)
				/// @return true if @a rawResponse looks like a PEBKAC.fr API error,
				/// false otherwise.
				bool responseIsError(const QByteArray rawResponse) const;
		};

	}
}

#endif // PEBKACREQUESTER_HPP
