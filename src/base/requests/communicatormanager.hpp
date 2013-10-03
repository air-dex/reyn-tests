/// @file communicatormanager.hpp
/// @brief Header of CommunicatorManager
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

#ifndef COMMUNICATORMANAGER_HPP
#define COMMUNICATORMANAGER_HPP

#include <QLinkedList>
#include "../communicators/communicator.hpp"

namespace LibRT {
	/// @class CommunicatorManager
	/// @brief Manager for communicators
	/// @see LibRT::RequesterManager
	class CommunicatorManager : protected QLinkedList<Communicator *>
	{
		public:
			/// @fn CommunicatorManager();
			/// @brief Constructs an empty map
			CommunicatorManager();

			/// @fn void addCommunicator(Communicator * communicator);
			/// @brief Storing a communicator
			/// @param communicator Entity executing the low level network tasks
			void addCommunicator(Communicator * communicator);

			/// @fn void removeCommunicator(Communicator * communicator);
			/// @brief Removing a communicator from the manager
			/// @param communicator Communicator to remove
			void removeCommunicator(Communicator * communicator);
	};
}


#endif // COMMUNICATORMANAGER_HPP
