/// @file getargs.hpp
/// @brief Header of the GetArgs struct.
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

#ifndef GETARGS_HPP
#define GETARGS_HPP

#include <QString>
#include <QUrl>
#include "httpargs.hpp"

namespace LibRT {
	/// @class GetArgs
	/// @brief HTTPArgs for GET arguments.
	///
	/// It gets a special method to build the whole url for the request
	/// (<code>QUrl getRequestURL();</code>). It builds the GET arguments and
	/// then appends them to the base URL.
	///
	/// The default behaviour of this class is building arguments like
	/// URL queries.
	class LIBRTSHARED_EXPORT GetArgs : public HTTPArgs
	{
		public:
			/// @fn GetArgs(ArgsMap args = ArgsMap());
			/// @brief Constructor
			/// @param args HTTP Arguments
			GetArgs(ArgsMap args = ArgsMap());

			/// @fn QUrl getRequestURL(QString baseURL);
			/// @brief Building the whole url for the request
			/// @param baseURL URL of the request endpoint.
			/// @return The whole url for the request, the one to give to the
			/// QNetworkRequest in the communicator.
			QUrl getRequestURL(QString baseURL);

			/// @fn virtual QString getBuiltArgs();
			/// @brief Building the HTTP args with the elements of the struct.
			/// @return Args of the struct built with the build(ArgsMap); method.
			virtual QString getBuiltArgs();
	};
}

#endif // GETARGS_HPP
