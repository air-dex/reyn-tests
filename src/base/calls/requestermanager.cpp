/// @file requestermanager.cpp
/// @brief Implementation of RequesterManager
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

#include "requestermanager.hpp"

using LibRT::GenericRequester;
using LibRT::RequesterManager;
using LibRT::RequestInfos;

// Constructor
RequesterManager::RequesterManager() :
	QMap<QUuid, RequestInfos>()
{}

// Adding a request to the manager
void RequesterManager::addRequest(QObject * asker, GenericRequester * requester) {
	if (requester != 0) {
		RequestInfos reqinf;

		reqinf.asker = asker;
		reqinf.requester = requester;

		insert(requester->getUuid(), reqinf);
	}
}

// Removing a request to the manager
void RequesterManager::removeRequest(GenericRequester * requester) {
	if (requester) {
		remove(requester->getUuid());
		delete requester;
	}
}

// Getting informations on a request
RequestInfos & RequesterManager::getRequestInfos(QUuid requestUuid) {
	return (*this)[requestUuid];
}

// Getting the QObject which asked for the request
QObject * RequesterManager::getAsker(GenericRequester * requester) {
	return requester ? getRequestInfos(requester->getUuid()).asker : 0;
}
