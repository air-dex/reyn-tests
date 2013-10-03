/// @file twitterauthenticator.hpp
/// @brief Header of TwitterAuthenticator
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

#ifndef TWITTERAUTHENTICATOR_HPP
#define TWITTERAUTHENTICATOR_HPP

#include "../base/authenticators/oauth/oauth10aauthenticator.hpp"
#include "../base/authenticators/oauth/oauth2authenticator.hpp"
#include "../base/librt_global.hpp"

namespace LibRT { namespace Twitter {

	/// @class TwitterAuthenticator
	/// @brief Class managing OAuth authentication to Twitter.
	///
	/// Twitter (and so Reyn Tweets) uses both OAuth 1.0a and OAuth 2.
	class LIBRTSHARED_EXPORT TwitterAuthenticator :
			public virtual OAuth10aAuthenticator,
			public virtual OAuth2Authenticator
	{
		public:
			/// @fn TwitterAuthenticator();
			/// @brief Constructor.
			///
			/// Application settings (callback URL, consumer credentials) will be
			/// filled later.
			TwitterAuthenticator();

			/// @fn virtual ~TwitterAuthenticator();
			/// @brief Destructor
			virtual ~TwitterAuthenticator();

			/// @fn void resetTokens();
			/// @brief Resetting the tokens. A full new OAuth authentication process
			/// has to be launch to get tokens and for authentication in requests
			void resetTokens();
	};

}}

#endif // TWITTERAUTHENTICATOR_HPP
