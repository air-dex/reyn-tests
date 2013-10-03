/// @file floppebkacsrequester.hpp
/// @brief Header of FlopPebkacsRequester
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

#ifndef FLOPPEBKACSREQUESTER_HPP
#define FLOPPEBKACSREQUESTER_HPP

#include "pebkacrequester.hpp"
#include "../pebkacconstants.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class FlopPebkacsRequester
		/// @brief Requester for Flop Pebkacs
		/// @see http://dev.pebkac.fr/doc/flop/
		class FlopPebkacsRequester : public PebkacRequester
		{
			public:
				/// @fn FlopPebkacsRequester(const PebkacAuthenticator & authPebkac,
				///							 int offset = OFFSET_DEFAULT_VALUE,
				///							 int limit = LIMIT_DEFAULT_VALUE,
				///							 QString period = PEBKAC_DEFAULT_PERIOD,
				///							 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param authPebkac Authentication datas for PEBKAC.fr
				/// @param offset First item of the list
				/// @param limit Number of PEBKACs to retrieve.
				/// @param period Period of time for retrieving PEBKACs
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				FlopPebkacsRequester(const PebkacAuthenticator & authPebkac,
									 int offset = OFFSET_DEFAULT_VALUE,
									 int limit = LIMIT_DEFAULT_VALUE,
									 QString period = PEBKAC_DEFAULT_PERIOD,
									 QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			protected:
				/// @brief Period of time for retrieving PEBKACs
				QString pebkacPeriod;

				/// @brief First item of the list
				int offset;

				/// @brief Number of PEBKACs to retrieve.
				int limit;

				/// @fn virtual ArgsMap buildGETParameters();
				/// @brief Virtual method building getParameters and
				/// the pattern they will fill.
				/// @return GET parameters that will be passed to the Communicator.
				virtual ArgsMap buildGETParameters();
		};
	}
}

#endif // FLOPPEBKACSREQUESTER_HPP
