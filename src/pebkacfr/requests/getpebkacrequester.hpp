/// @file getpebkacrequester.hpp
/// @brief Header of GetPebkacRequester
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

#ifndef GETPEBKACREQUESTER_HPP
#define GETPEBKACREQUESTER_HPP

#include "pebkacrequester.hpp"
#include "../../base/utils/librtconstants.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class GetPebkacRequester
		/// @brief Requester for getting a PEBKAC
		/// @see http://dev.pebkac.fr/doc/pebkac/
		class GetPebkacRequester : public PebkacRequester
		{
			public:
				/// @fn GetPebkacRequester(const PebkacAuthenticator & authPebkac,
				///						   int idPebkac,
				///						   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param authPebkac Authentication datas for PEBKAC.fr
				/// @param idPebkac ID of the PEBKAC.
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				GetPebkacRequester(const PebkacAuthenticator & authPebkac,
								   int idPebkac,
								   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			protected:
				/// @brief First item of the list
				int pebkacID;

				/// @fn virtual ArgsMap buildGETParameters();
				/// @brief Virtual method building getParameters and
				/// the pattern they will fill.
				/// @return GET parameters that will be passed to the Communicator.
				virtual ArgsMap buildGETParameters();
		};
	}
}

#endif // GETPEBKACREQUESTER_HPP
