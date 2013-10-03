/// @file communicatormanager.cpp
/// @brief Implementation of CommunicatorManager
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

#include "communicatormanager.hpp"

using LibRT::CommunicatorManager;
using LibRT::Communicator;

// Constructor
CommunicatorManager::CommunicatorManager() :
	QLinkedList<Communicator *>()
{}

// Storing a communicator
void CommunicatorManager::addCommunicator(Communicator * communicator) {
	if (communicator != 0) {
		this->append(communicator);
	}
}

// Removing a communicator from the manager
void CommunicatorManager::removeCommunicator(Communicator * communicator) {
	if (communicator != 0) {
		this->removeAll(communicator);
		delete communicator;
	}
}
