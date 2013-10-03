/// @file httpargs.hpp
/// @brief Header of the HTTPArgs struct.
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

#ifndef HTTPARGS_HPP
#define HTTPARGS_HPP

#include <QString>
#include "../headersmap.hpp"
#include "../librt_global.hpp"

namespace LibRT {
	/// @class HTTPArgs
	/// @brief Class for storing and building HTTP arguments of a given kind
	/// (GET, POST, PUT...).
	///
	/// One of the Communicator's role is preparing HTTP arguments for network
	/// requests. However the way to prepare them can change from one service to
	/// another and sometimes from one service request to another.
	///
	/// Inheriting Communicator might be a suitable solution for this problem.
	/// It would be an interesting solution if each service would have a simple
	/// way to do it for all its requests. Each service would have got its own
	/// "<code>ServiceCommunicator</code>" which would inherit Communicator
	/// and would implement the methods dealing with how to prepare the args.
	/// But it is not the case because the way to prepare HTTP arguments can
	/// depend on the request for a given service (ex. PEBKAC.fr). In this case
	/// LibRT code maintenance can quickly become complicated if Communicator
	/// has to inherited for each requester.
	///
	/// The HTTPArgs class is designed to solve this problem. It contains the
	/// HTTP arguments and the function to build what will be in the HTTP
	/// request. The class is given to the Communicator who will use the <code>
	/// QString build();</code> function to prepare HTTP arguments with the high
	/// level arguments which are in the <code>httpArgs</code> ArgsMap.
	///
	/// The default behaviour of this class is building arguments like
	/// URL queries.
	class LIBRTSHARED_EXPORT HTTPArgs
	{
		public:
			/// @fn HTTPArgs(ArgsMap args = ArgsMap());
			/// @brief Constructor
			/// @param args HTTP Arguments
			HTTPArgs(ArgsMap args = ArgsMap());

			/// @fn virtual QString getBuiltArgs();
			/// @brief Building the HTTP args with the elements of the struct.
			/// @return Args of the struct built with the build(ArgsMap); method.
			virtual QString getBuiltArgs();

			/// @fn ArgsMap getHttpArgs() const;
			/// @brief Getter on httpArgs
			/// @return httpArgs
			ArgsMap getHttpArgs() const;

		protected:
			/// @brief "High level" arguments under a QString form.
			ArgsMap httpArgs;
	};
}


#endif // HTTPARGS_HPP
