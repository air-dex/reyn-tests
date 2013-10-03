/// @file twitlongerauthenticator.hpp
/// @brief Header of TwitLongerAuthenticator
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2012, 2013 Romain Ducher
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

#ifndef TWITLONGERAUTHENTICATOR_HPP
#define TWITLONGERAUTHENTICATOR_HPP

#include <QString>
#include "../base/authenticators/apikeyauthenticator.hpp"
#include "../base/librt_global.hpp"

namespace LibRT { namespace TwitLonger {

	/// @class TwitLongerAuthenticator
	/// @brief Entity with all the informations needed for transactions with the
	/// TwitLonger API.
	class LIBRTSHARED_EXPORT TwitLongerAuthenticator : public APIKeyAuthenticator
	{
		public:
			/// @fn TwitLongerAuthenticator();
			/// @brief Default constructor. Settings will be filled later.
			TwitLongerAuthenticator();

			/// @fn QString getApplicationName() const;
			/// @brief Getting the application name
			/// @return applicationName
			QString getApplicationName() const;

			/// @fn void setApplicationName(QString newAppName);
			/// @brief Setting the application name
			/// @param newAppName New value for applicationName
			void setApplicationName(QString newAppName);

		protected:
			/// @brief Name of the application on TwitLonger
			QString applicationName;
	};

}}

#endif // TWITLONGERAUTHENTICATOR_HPP
