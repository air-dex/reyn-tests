/// @file searchrequester.hpp
/// @brief Header of SearchRequester
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2011, 2013 Romain Ducher
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

#ifndef SEARCHREQUESTER_HPP
#define SEARCHREQUESTER_HPP

#include "../twitterrequester.hpp"

namespace LibRT { namespace Twitter {

	/// @class SearchRequester
	/// @brief Requester for searches
	/// @see https://dev.twitter.com/docs/api/1/get/search
	class SearchRequester : public TwitterRequester
	{
		Q_OBJECT

		public:
			/// @fn SearchRequester(const TwitterAuthenticator & authManager,
			///						QString q = "",
			///						QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);
			/// @brief Constructor
			/// @param authManager Entity with authentication datas. Introduced with
			/// Twitter API 1.1 changes.
			/// @param q The query
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			SearchRequester(const TwitterAuthenticator & authManager,
							QString q = "",
							QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief Query made by the user
			QString query;

			/// @fn ArgsMap buildGETParameters();
			/// @brief Building getParameters
			ArgsMap buildGETParameters();
	};

}}

#endif // SEARCHREQUESTER_HPP
