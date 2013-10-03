/// @file requestresult.hpp
/// @brief Header of RequestResult
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

#ifndef REQUESTRESULT_HPP
#define REQUESTRESULT_HPP

#include <QVariant>
#include "networkresulttype.hpp"
#include "responseinfos.hpp"
#include "utils/httpcode.hpp"
#include "librt_global.hpp"

namespace LibRT {
	/// @struct RequestResult
	/// @brief Results of a request
	struct LIBRTSHARED_EXPORT RequestResult {
			/// @brief Code indicating whether an error occured during the request.
			NetworkResultType resultType;

			/// @brief Parsed results.
			QVariant parsedResult;

			/// @brief HTTP response (code and reason)
			ResponseInfos httpResponse;

			/// @brief Services (ex. Twitter) error responses (code and reason)
			QList<ResponseInfos> serviceErrors;

			/// @brief Potential errors that can occur while parsing results.
			///
			/// The message field is the error message while the code field is the
			/// number of the line where the error occured.
			ResponseInfos parsingErrors;

			/// @brief Error message
			QString errorMessage;

			/// @fn RequestResult();
			/// @brief Constructor
			RequestResult() :
				resultType(INVALID_RESULT),
				parsedResult(),
				httpResponse(),
				serviceErrors(),
				parsingErrors(),
				errorMessage("")
			{}

			/// @fn LibRT::HTTPCode getHTTPCode();
			/// @brief HTTP response code (shortcut)
			/// @return The HTTP response code as a LibRT::HTTPCode.
			HTTPCode getHTTPCode() {
				return HTTPCode(httpResponse.code);
			}
	};
}

#endif // REQUESTRESULT_HPP
