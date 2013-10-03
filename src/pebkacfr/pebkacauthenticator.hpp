/// @file pebkacauthenticator.hpp
/// @brief Header of PebkacAuthenticator
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

#ifndef PEBKACAUTHENTICATOR_HPP
#define PEBKACAUTHENTICATOR_HPP

#include <QString>
#include "../base/librt_global.hpp"
#include "../base/authenticators/apikeyauthenticator.hpp"
#include "../base/networkresulttype.hpp"

namespace LibRT {
	namespace Pebkac {

		/// @class PebkacAuthenticator
		/// @brief Authenticator for the <a href="http://dev.pebkac.fr/">
		/// PEBKAC.fr API</a>.
		/// @see http://dev.pebkac.fr/
		class LIBRTSHARED_EXPORT PebkacAuthenticator : public APIKeyAuthenticator
		{
			public:
				/// @fn PebkacAuthenticator();
				/// @brief Constructor
				PebkacAuthenticator();

				/// @fn virtual ~PebkacAuthenticator();
				/// @brief Destructor
				virtual ~PebkacAuthenticator();

				/// @fn QByteArray getUserAgent() const;
				/// @brief Getter on the User Agent
				/// @return userAgent
				QByteArray getUserAgent() const;

				/// @fn void setUserAgent(const QByteArray &newAgent);
				/// @brief Setter on the User Agent
				/// @param newAgent New value for userAgent
				void setUserAgent(const QByteArray &newAgent);

				/// @fn NetworkResultType getOutputFormat() const;
				/// @brief Getter on the Output Format
				/// @return outputFormat
				NetworkResultType getOutputFormat() const;

				/// @fn void setOutputFormat(const NetworkResultType &newFormat);
				/// @brief Setter on the Output Format
				/// @param newFormat New value for userAgent
				void setOutputFormat(const NetworkResultType &newFormat);

			protected:
				/// @brief Application's user agent for PEBKAC.fr
				QByteArray userAgent;

				/// @brief Output format for datas. PEBKAC.fr API currently accepts
				/// JSON and XML. The output format must match with the application
				/// output format chosen by its owner.
				///
				/// The output format has a strict equivalence with the request's
				/// NetworkResultType. If the parsing operation fails, the
				/// NetworkResultType will be a parsing error related to the output
				/// format, i.e. JSON_PARSING for JSON and XML_PARSING for XML.
				/// That's why the type of @a outputFormat is NetworkResultType.
				NetworkResultType outputFormat;
		};

	}
}

#endif // PEBKACAUTHENTICATOR_HPP
