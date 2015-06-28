/*
* Copyright (c) 2015 Jean-Sébastien Fauteux
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from
* the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it freely,
* subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not claim
*    that you wrote the original software. If you use this software in a product,
*    an acknowledgment in the product documentation would be appreciated but is
*    not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source distribution.
*/
#include "message_handler.hpp"

#include <iostream>

void PhysicsMessageHandler::onMessage(Message& message) {
	auto realMessage = message.getMessage<PhysicMessage>();

	if(realMessage) {
		std::cout << "Message is Physic\n";
	}
}

void GraphicMessageHandler::onMessage(Message& message) {
	auto realMessage = message.getMessage<GraphicMessage>();

	if(realMessage) {
		std::cout << "Message is Graphic\n";
	}
}

void NetworkMessageHandler::onMessage(Message& message) {
	auto realMessage = message.getMessage<NetworkMessage>();

	if(realMessage) {
		std::cout << "Message is Network\n";
	}
}
