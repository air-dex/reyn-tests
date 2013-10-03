/// @file pebkaccalls.cpp
/// @brief Implementation of PebkacCalls
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

#include "pebkaccalls.hpp"
#include "requests/pebkacrequesters.hpp"

using PEBKAC::PebkacAuthenticator;
using PEBKAC::LatestPebkacsRequester;
using PEBKAC::TopPebkacsRequester;
using PEBKAC::FlopPebkacsRequester;
using PEBKAC::RandomPebkacsRequester;
using PEBKAC::AllPebkacfrUsersRequester;
using PEBKAC::UserPebkacsRequester;
using PEBKAC::AllPebkacTagsRequester;
using PEBKAC::PebkacTagRequester;
using PEBKAC::GetPebkacRequester;
using PEBKAC::PebkacCommentsRequester;

PEBKAC::PebkacCalls::PebkacCalls(QObject *requester,
								 const PebkacAuthenticator &authPebkac,
								 QNetworkAccessManager &netManager) :
	LibRT::GenericCalls(requester, netManager),
	pebkacAuth(authPebkac)
{}

// Destructor
PEBKAC::PebkacCalls::~PebkacCalls() {}


/////////////////////////
// Requests to the API //
/////////////////////////

// Retrieving the latest PEBKACs.
void PEBKAC::PebkacCalls::getLatestPebkacs(int offset, int limit) {
	LatestPebkacsRequester * requester = new LatestPebkacsRequester(pebkacAuth,
																	offset,
																	limit,
																	network);

	executeRequest(requester);
}

// Retrieving Top Pebkacs
void PEBKAC::PebkacCalls::getTopPebkacs(int offset, int limit, QString period) {
	TopPebkacsRequester * requester = new TopPebkacsRequester(pebkacAuth,
															  offset,
															  limit,
															  period,
															  network);

	executeRequest(requester);
}

// Retrieving Flop Pebkacs
void PEBKAC::PebkacCalls::getFlopPebkacs(int offset, int limit, QString period) {
	FlopPebkacsRequester * requester = new FlopPebkacsRequester(pebkacAuth,
																offset,
																limit,
																period,
																network);

	executeRequest(requester);
}

// Getting Random Pebkacs
void PEBKAC::PebkacCalls::getRandomPebkacs(int nbPebkacs) {
	RandomPebkacsRequester * requester = new RandomPebkacsRequester(pebkacAuth,
																	nbPebkacs,
																	network);

	executeRequest(requester);
}

// Retrieving all the PEBKAC.fr registered users.
void PEBKAC::PebkacCalls::getAllPebkacfrMembers() {
	AllPebkacfrUsersRequester * requester = new AllPebkacfrUsersRequester(pebkacAuth,
																		  network);

	executeRequest(requester);
}

// Getting PEBKACs of a user
void PEBKAC::PebkacCalls::getUserPebkacs(int idUser, int offset, int limit) {
	UserPebkacsRequester * requester = new UserPebkacsRequester(pebkacAuth,
																idUser,
																offset,
																limit,
																network);

	executeRequest(requester);
}

// Retrieving all the PEBKAC tags.
void PEBKAC::PebkacCalls::getAllPebkacTags() {
	AllPebkacTagsRequester * requester = new AllPebkacTagsRequester(pebkacAuth,
																	network);

	executeRequest(requester);
}

// Retrieving PEBKACs related to a given tag.
void PEBKAC::PebkacCalls::getPebkacTag(QString uriTag, int offset, int limit) {
	PebkacTagRequester * requester = new PebkacTagRequester(pebkacAuth,
															uriTag,
															offset,
															limit,
															network);

	executeRequest(requester);
}

// Getting a precise PEBKAC
void PEBKAC::PebkacCalls::getPebkac(int idPebkac) {
	GetPebkacRequester * requester = new GetPebkacRequester(pebkacAuth,
															idPebkac,
															network);

	executeRequest(requester);
}

// Retrieving Comments of a given PEBKAC
void PEBKAC::PebkacCalls::getPebkacComments(int idPebkac) {
	PebkacCommentsRequester * requester = new PebkacCommentsRequester(pebkacAuth,
																	  idPebkac,
																	  network);

	executeRequest(requester);
}
