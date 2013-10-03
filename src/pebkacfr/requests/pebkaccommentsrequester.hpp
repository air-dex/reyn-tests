/// @file pebkaccommentsrequester.hpp
/// @brief Header of PebkacCommentsRequester
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

#ifndef PEBKACCOMMENTSREQUESTER_HPP
#define PEBKACCOMMENTSREQUESTER_HPP

#include "pebkacrequester.hpp"
#include "../pebkacconstants.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class PebkacCommentsRequester
		/// @brief Requester for Comments of a given PEBKAC
		/// @see http://dev.pebkac.fr/doc/comments/
		class PebkacCommentsRequester : public PebkacRequester
		{
			public:
				/// @fn PebkacCommentsRequester(const PebkacAuthenticator & authPebkac,
				///								int idPebkac,
				///								QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param authPebkac Authentication datas for PEBKAC.fr
				/// @param idPebkac ID of the PEBKAC whose comments are retrieved
				/// by this Requester.
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				PebkacCommentsRequester(const PebkacAuthenticator & authPebkac,
										int idPebkac,
										QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			protected:
				/// @brief First item of the list
				int pebkacID;

				/// @fn virtual ArgsMap buildGETParameters();
				/// @brief Virtual method building getParameters and
				/// the pattern they will fill.
				/// @return GET parameters that will be passed to the Communicator.
				virtual LibRT::ArgsMap buildGETParameters();
		};
	}
}

#endif // PEBKACCOMMENTSREQUESTER_HPP
