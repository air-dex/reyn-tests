/// @file requestinfos.hpp
/// @brief Header of RequestInfos
/// @author Romain Ducher
///
/// @section LICENSE
///
/// Copyright 2012, 2013 Romain Ducher
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

#ifndef REQUESTINFOS_HPP
#define REQUESTINFOS_HPP

#include <QObject>
#include "../requests/genericrequester.hpp"

namespace LibRT {
	/// @struct RequestInfos
	/// @brief Struct containing the entity which asks for the request
	/// (the "asker") and the requester that executes the request (the "requester").
	struct RequestInfos {
			/// @brief Entity which asks for the request
			QObject * asker;

			/// @brief Requester that executes the request
			GenericRequester * requester;
	};
}

#endif // REQUESTINFOS_HPP
