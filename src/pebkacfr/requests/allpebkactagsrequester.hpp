/// @file allpebkactagsrequester.hpp
/// @brief Header of AllPebkacTagsRequester
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

#ifndef ALLPEBKACTAGSREQUESTER_HPP
#define ALLPEBKACTAGSREQUESTER_HPP

#include "pebkacrequester.hpp"
#include "../../base/utils/librtconstants.hpp"

namespace LibRT {
	namespace Pebkac {
		/// @class AllPebkacTagsRequester
		/// @brief Requester for retrieving all the PEBKAC tags.
		/// @see http://dev.pebkac.fr/doc/taglist/
		class AllPebkacTagsRequester : public PebkacRequester
		{
			public:
				/// @fn AllPebkacTagsRequester(const PebkacAuthenticator & authPebkac,
				///							   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
				/// @brief Constructor
				/// @param authPebkac Authentication datas for PEBKAC.fr
				/// @param netManager Entity managing low level network tasks.
				/// Dependency injection for custom network accesses just like
				/// mocks for tests.
				AllPebkacTagsRequester(const PebkacAuthenticator & authPebkac,
									   QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
		};
	}
}

#endif // ALLPEBKACTAGSREQUESTER_HPP
