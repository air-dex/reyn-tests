/// @file responseinfos.hpp
/// @brief Header of ResponseInfos
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

#ifndef RESPONSEINFOS_HPP
#define RESPONSEINFOS_HPP

#include <QString>
#include "librt_global.hpp"

namespace LibRT {
	/// @struct ResponseInfos
	/// @brief Struct with an integer (field "code") and its meaning (field "message").
	///
	/// When used to store JSON parsing errors, "message" is the error message and
	/// "code" the offset.
	struct LIBRTSHARED_EXPORT ResponseInfos {
			/// @brief Code
			int code;

			/// @brief Decription of the code
			QString message;
			/*
		/// @fn ResponseInfos();
		/// @brief Constructor
		ResponseInfos() : code(-1), message("") {}
	//*/
			/// @fn ResponseInfos(int codeNum = -1, QString msg = "");
			/// @brief Full constructor
			/// @param codeNum Value for code
			/// @param msg Value for message
			ResponseInfos(int codeNum = -1, QString msg = "") :
				code(codeNum),
				message(msg)
			{}
	};
}

#endif // RESPONSEINFOS_HPP
