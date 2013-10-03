/// @file sendidtotwitlongerrequester.hpp
/// @brief Header of SendIDToTwitLongerRequester
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

#ifndef SENDIDTOTWITLONGERREQUESTER_HPP
#define SENDIDTOTWITLONGERREQUESTER_HPP

#include "twitlongerrequester.hpp"

namespace LibRT { namespace TwitLonger {

	/// @class SendIDToTwitLongerRequester
	/// @brief Request to update informations about a long message on TwitLonger.
	class SendIDToTwitLongerRequester : public TwitLongerRequester
	{
		Q_OBJECT

		public:
			/// @fn SendIDToTwitLongerRequester(const TwitLongerAuthenticator & manager,
			///									QString tlMessageID,
			///									qlonglong statusID,
			///									QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER
			/// @brief Constructor
			/// @param manager Entity with TwitLonger authentications data
			/// @param tlMessageID TwitLonger ID of the message
			/// @param statusID ID of the tweet in Twitter's databases
			/// @param netManager Entity managing low level network tasks.
			/// Dependency injection for custom network accesses just like
			/// mocks for tests.
			SendIDToTwitLongerRequester(const TwitLongerAuthenticator & manager,
										QString tlMessageID,
										qlonglong statusID,
										QNetworkAccessManager & netManager = LIBRT_NETWORK_MANAGER);

		protected:
			/// @brief ID of the long message on TwitLonger
			QString messageID;

			/// @brief ID of the shortened message on Twitter
			qlonglong tweetID;

			/// @fn ArgsMap buildPOSTParameters();
			/// @brief Building parameters for the request
			ArgsMap buildPOSTParameters();

			/// @fn QDomElement getInfoElement(QDomElement xmlRoot);
			/// @brief Getting the XML element with all the necessary informations.
			///
			/// The XML reply of this kind of request get a "twitlonger" root tag
			/// which gets a unique child with th interesting informations so the
			/// method will return it.
			/// @param xmlRoot Root of the XML reply.
			/// @return The node which contains the informations.
			QDomElement getInfoElement(QDomElement xmlRoot);
	};

}}

#endif // SENDIDTOTWITLONGERREQUESTER_HPP
