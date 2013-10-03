/// @file showuserrequester.hpp
/// @brief Header of ShowUserRequester
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

#ifndef SHOWUSERREQUESTER_HPP
#define SHOWUSERREQUESTER_HPP

#include <QString>
#include "../twitterrequester.hpp"
#include "../../../base/requests/identificationway.hpp"

namespace LibRT { namespace Twitter {

	/// @class ShowUserRequester
	/// @brief Requester for getting details about a user identified by its ID
	/// or its screen name.
	/// @see https://dev.twitter.com/docs/api/1.1/get/users/show
	class ShowUserRequester : public TwitterRequester
	{
		public:
			/// @fn ShowUserRequester(const TwitterAuthenticator & authManager,
			///						  qlonglong id,
			///						  bool entities = true,
			///						  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor with the user ID
			/// @param authManager TwitterAuthenticator for authentication
			/// @param id User ID
			/// @param entities Include entities in the last tweet of the user ?
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			ShowUserRequester(const TwitterAuthenticator & authManager,
							  qlonglong id,
							  bool entities = true,
							  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			/// @fn ShowUserRequester(const TwitterAuthenticator & authManager,
			///						  QString name,
			///						  bool entities = true,
			///						  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor with the screen name
			/// @param authManager TwitterAuthenticator for authentication
			/// @param name Screen name
			/// @param entities Include entities in the last tweet of the user ?
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			ShowUserRequester(const TwitterAuthenticator & authManager,
							  QString name,
							  bool entities = true,
							  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief How the user is identified
			LibRT::IdentificationWay idWay;


			////////////////
			// Parameters //
			////////////////

			/// @brief ID of the user
			qlonglong userID;

			/// @brief Boolean indicating if entities of a tweet have to be included
			/// in the reply
			bool includeEntities;

			/// @brief When this value is set to true, only the id and id_str values
			/// of the user are returned.
			QString screenName;

			/// @fn ArgsMap buildGETParameters();
			/// @brief Building getParameters
			ArgsMap buildGETParameters();
	};

}}

#endif // SHOWUSERREQUESTER_HPP
