/// @file httprequesttype.hpp
/// @brief Header of LibRT::HTTPRequestType
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

#ifndef HTTPREQUESTTYPE_HPP
#define HTTPREQUESTTYPE_HPP

#include <QString>
#include "librt_global.hpp"

namespace LibRT {
	/// @enum HTTPRequestType
	/// @brief Enum indicating the type of the request
	enum LIBRTSHARED_EXPORT HTTPRequestType {
		/// @brief GET requests
		GET,

		/// @brief POST requests
		POST
	};
}

#endif // HTTPREQUESTTYPE_HPP
