/// @file latestpebkacsrequester.hpp
/// @brief Header of LatestPebkacsRequester
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

#ifndef LATESTPEBKACSREQUESTER_HPP
#define LATESTPEBKACSREQUESTER_HPP

#include "../pebkacconstants.hpp"
#include "pebkacrequester.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class LatestPebkacsRequester
		/// @brief Retrieving the latest PEBKACs.
		/// @see http://dev.pebkac.fr/doc/latest/
		class LatestPebkacsRequester : public PebkacRequester
		{
			public:
				/// @fn LatestPebkacsRequester(const PebkacAuthenticator & authPebkac,
				///							   int offset = OFFSET_DEFAULT_VALUE,
				///							   int limit = LIMIT_DEFAULT_VALUE,
				///							   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param authPebkac Authentication datas for PEBKAC.fr
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				LatestPebkacsRequester(const PebkacAuthenticator & authPebkac,
									   int offset = OFFSET_DEFAULT_VALUE,
									   int limit = LIMIT_DEFAULT_VALUE,
									   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			protected:
				/// @brief First item of the list
				int offset;

				/// @brief Number of PEBKACs to retrieve.
				int limit;

				/// @fn virtual ArgsMap buildGETParameters();
				/// @brief Virtual method building GET Parameters and
				/// the pattern they will fill.
				/// @return GET parameters that will be passed to the Communicator.
				virtual ArgsMap buildGETParameters();
		};
	}
}

//*/

#endif // LATESTPEBKACSREQUESTER_HPP
