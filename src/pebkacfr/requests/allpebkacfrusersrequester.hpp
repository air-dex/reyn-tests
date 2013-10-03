/// @file allpebkacfrusersrequester.hpp
/// @brief Header of AllPebkacfrUsersRequester
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

#ifndef ALLPEBKACFRUSERSREQUESTER_HPP
#define ALLPEBKACFRUSERSREQUESTER_HPP

#include "pebkacrequester.hpp"
#include "../../base/utils/librtconstants.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class AllPebkacfrUsersRequester
		/// @brief Requester for retrieving all the PEBKAC.fr registered users.
		/// @see http://dev.pebkac.fr/doc/userlist/
		class AllPebkacfrUsersRequester : public PebkacRequester
		{
			public:
				/// @fn AllPebkacfrUsersRequester(const PebkacAuthenticator & authPebkac,
				///								  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param authPebkac Authentication datas for the PEBKAC API
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				AllPebkacfrUsersRequester(const PebkacAuthenticator & authPebkac,
										  QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		};
	}
}

#endif // ALLPEBKACFRUSERSREQUESTER_HPP
