/// @file oauth2authenticator.hpp
/// @brief Header of OAuth2Authenticator
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

#ifndef OAUTH2AUTHENTICATOR_HPP
#define OAUTH2AUTHENTICATOR_HPP

#include "oauthauthenticator.hpp"
#include "../../librt_global.hpp"

namespace LibRT {
	/// @class OAuth2Authenticator
	/// @brief Authenticator for stuff related to OAuth 2.
	class LIBRTSHARED_EXPORT OAuth2Authenticator : public virtual OAuthAuthenticator
	{
		public:
			/// @fn OAuth2Authenticator();
			/// @brief Constructor
			OAuth2Authenticator();

			/// @fn virtual ~OAuth2Authenticator();
			/// @brief Destructor
			virtual ~OAuth2Authenticator();

			/// @fn void setBearerToken(QByteArray newBearer);
			/// @brief Setter for bearerToken
			/// @param newBearer New value for bearerToken
			void setBearerToken(QByteArray newBearer);

			/// @fn void resetTokens();
			/// @brief Resetting the tokens. A full new OAuth authentication process
			/// has to be launch to get tokens and for authentication in requests
			void resetTokens();

			/// @fn QByteArray getBasicHeader() const;
			/// @brief Building the header used to retrieve or to invalidate
			/// a Bearer Token.
			/// @return The corresponding header
			QByteArray getBasicHeader() const;

			/// @fn QByteArray getBearerHeader() const;
			/// @brief Building the header used to authenticate requests.
			/// @return The corresponding header
			QByteArray getBearerHeader() const;

		protected:
			/// @brief Bearer token
			QByteArray bearerToken;
	};
}

#endif // OAUTH2AUTHENTICATOR_HPP
