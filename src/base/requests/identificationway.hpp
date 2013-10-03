/// @file identificationway.hpp
/// @brief Header of LibRT::IdentificationWay
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

#ifndef IDENTIFICATIONWAY_HPP
#define IDENTIFICATIONWAY_HPP

namespace LibRT {
	/// @enum IdentificationWay
	/// @brief How the user is identified in a request ?
	enum IdentificationWay {
		/// @brief With an ID.
		ID,

		/// @brief With a screen name
		SCREEN_NAME
	};
}

#endif // IDENTIFICATIONWAY_HPP
