/// @file randompebkacsrequester.hpp
/// @brief Header of RandomPebkacsRequester
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

#ifndef RANDOMPEBKACSREQUESTER_HPP
#define RANDOMPEBKACSREQUESTER_HPP

#include "pebkacrequester.hpp"
#include "../pebkacconstants.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class RandomPebkacsRequester
		/// @brief Requester for a list of random PEBKACs
		/// @see http://dev.pebkac.fr/doc/random/
		class RandomPebkacsRequester : public PebkacRequester
		{
			public:
				/// @fn RandomPebkacsRequester(const PebkacAuthenticator & authPebkac,
				///							   int nbPebkacs = LIMIT_DEFAULT_VALUE,
				///							   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				///	@brief Constructor
				///	@param nbPebkacs Number of random PEBKACs to retrieve.
				RandomPebkacsRequester(const PebkacAuthenticator & authPebkac,
									   int nbPebkacs = LIMIT_DEFAULT_VALUE,
									   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

			protected:
				/// @brief Number of random PEBKACs to retrieve.
				int count;

				/// @fn virtual ArgsMap buildGETParameters();
				/// @brief Virtual method building getParameters and
				/// the pattern they will fill.
				/// @return GET parameters that will be passed to the Communicator.
				virtual LibRT::ArgsMap buildGETParameters();
		};
	}
}

#endif // RANDOMPEBKACSREQUESTER_HPP
