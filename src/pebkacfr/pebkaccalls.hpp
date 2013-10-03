/// @file pebkaccalls.hpp
/// @brief Header of PebkacCalls
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

#ifndef PEBKACCALLS_HPP
#define PEBKACCALLS_HPP

#include <QString>
#include "../base/librt_global.hpp"
#include "../base/calls/genericcalls.hpp"
#include "pebkacconstants.hpp"
#include "pebkacauthenticator.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class PebkacCalls
		/// @brief Calls for the PEBKAC.fr API.
		/// @see http://dev.pebkac.fr/
		class LIBRTSHARED_EXPORT PebkacCalls : public GenericCalls
		{
			Q_OBJECT

			public:
				/// @fn PebkacCalls(QObject * requester,
				///					const PebkacAuthenticator & authPebkac,
				///					QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param requester Entity asking for the request
				/// @param authPebkac Authenticator for the PEBKAC.fr API.
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				PebkacCalls(QObject * requester,
							const PebkacAuthenticator & authPebkac,
							QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

				/// @fn virtual ~PebkacCalls();
				/// @brief Destructor
				virtual ~PebkacCalls();

			protected:
				/// @brief Authentication datas for the PEBKAC.fr API.
				const PebkacAuthenticator & pebkacAuth;


			public:
				/////////////////////////
				// Requests to the API //
				/////////////////////////

				/// @fn void getLatestPebkacs(int offset = OFFSET_DEFAULT_VALUE,
				///							  int limit = LIMIT_DEFAULT_VALUE);
				/// @brief Retrieving the latest PEBKACs.
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				void getLatestPebkacs(int offset = OFFSET_DEFAULT_VALUE,
									  int limit = LIMIT_DEFAULT_VALUE);

				/// @fn void getTopPebkacs(int offset = OFFSET_DEFAULT_VALUE,
				///						   int limit = LIMIT_DEFAULT_VALUE,
				///						   QString period = PEBKAC_DEFAULT_PERIOD);
				/// @brief Retrieving Top Pebkacs
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				/// @param period Period of time for retrieving PEBKACs
				void getTopPebkacs(int offset = OFFSET_DEFAULT_VALUE,
								   int limit = LIMIT_DEFAULT_VALUE,
								   QString period = PEBKAC_DEFAULT_PERIOD);

				/// @fn void getFlopPebkacs(int offset = OFFSET_DEFAULT_VALUE,
				///							int limit = LIMIT_DEFAULT_VALUE,
				///							QString period = PEBKAC_DEFAULT_PERIOD);
				/// @brief Retrieving Flop Pebkacs
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				/// @param period Period of time for retrieving PEBKACs
				void getFlopPebkacs(int offset = OFFSET_DEFAULT_VALUE,
									int limit = LIMIT_DEFAULT_VALUE,
									QString period = PEBKAC_DEFAULT_PERIOD);

				/// @fn void getRandomPebkacs(int nbPebkacs = LIMIT_DEFAULT_VALUE);
				/// @brief Getting Random Pebkacs
				///	@param nbPebkacs Number of random PEBKACs to retrieve.
				void getRandomPebkacs(int nbPebkacs = LIMIT_DEFAULT_VALUE);

				/// @fn void getAllPebkacfrMembers();
				/// @brief Retrieving all the PEBKAC.fr registered users.
				void getAllPebkacfrMembers();

				/// @fn void getUserPebkacs(int idUser,
				///							int offset = OFFSET_DEFAULT_VALUE,
				///							int limit = LIMIT_DEFAULT_VALUE);
				/// @brief Getting PEBKACs of a user
				/// @param idUser ID of the user whose PEBKACs are retrieved by
				/// this requester.
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				void getUserPebkacs(int idUser,
									int offset = OFFSET_DEFAULT_VALUE,
									int limit = LIMIT_DEFAULT_VALUE);

				/// @fn void getAllPebkacTags();
				/// @brief Retrieving all the PEBKAC tags.
				void getAllPebkacTags();

				/// @fn void getPebkacTag(QString uriTag,
				///						  int offset = OFFSET_DEFAULT_VALUE,
				///						  int limit = LIMIT_DEFAULT_VALUE);
				/// @brief Retrieving PEBKACs related to a given tag.
				/// @param uriTag URI of the tag
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				void getPebkacTag(QString uriTag,
								  int offset = OFFSET_DEFAULT_VALUE,
								  int limit = LIMIT_DEFAULT_VALUE);

				/// @fn void getPebkac(int idPebkac);
				/// @brief Getting a precise PEBKAC
				/// @param idPebkac ID of the PEBKAC.
				void getPebkac(int idPebkac);

				/// @fn void getPebkacComments(int idPebkac);
				/// @brief Retrieving Comments of a given PEBKAC
				/// @param idPebkac ID of the PEBKAC whose comments are retrieved
				/// by this Requester.
				void getPebkacComments(int idPebkac);
		};
	}
}

#endif // PEBKACCALLS_HPP
