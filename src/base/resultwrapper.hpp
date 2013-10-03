/// @file resultwrapper.hpp
/// @brief Header of ResultWrapper
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

#ifndef RESULTWRAPPER_HPP
#define RESULTWRAPPER_HPP

#include <QObject>
#include "requestresult.hpp"
#include "librt_global.hpp"

namespace LibRT {
	/// @class ResultWrapper
	/// @brief Class containg result of requests (field "result") and the QObject
	/// which asks for it (field "asker").
	///
	/// Only the sender of the request is allowed
	/// to have access to the result. It has to give its memory address in order to
	/// prove that it is the real sender of the request.
	class LIBRTSHARED_EXPORT ResultWrapper
	{
		public:
			/// @fn ResultWrapper();
			/// @brief Default constructor which builds an invalid wrapper.
			ResultWrapper();

			/// @fn ResultWrapper(QObject * requestSender, RequestResult requestResult);
			/// @brief Constructor
			/// @param requestSender Sender of the reqauest
			/// @param requestResult Result of the request
			ResultWrapper(QObject * requestSender, RequestResult requestResult);

			/// @fn RequestResult accessResult(QObject * demanderAdress);
			/// @brief Method to access to the result
			/// @param demanderAdress Memory address of the QObject which wants to access
			/// to the result.
			/// @return The request result if demanderAdress is right or Qvariant()
			/// otherwise.
			RequestResult accessResult(QObject * demanderAdress);

		protected:
			/// @brief Sender of the request
			QObject * asker;

			/// @brief Result of the request
			RequestResult result;
	};
}

#endif // RESULTWRAPPER_HPP
