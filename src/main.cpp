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
#include "message_dispatcher.hpp"
#include "message_handler.hpp"

int main() {
	MessageDispatcher dispatcher;

	PhysicsMessageHandler pmh;
	GraphicMessageHandler gmh;
	NetworkMessageHandler nmh;

	dispatcher.addHandler(&pmh);
	dispatcher.addHandler(&gmh);
	dispatcher.addHandler(&nmh);

	dispatcher.addPriorityHandler(networkMessageHash(), std::bind(&NetworkMessageHandler::onMessage, &nmh, std::placeholders::_1));
	//Could do this too with a lambda
	/*dispatcher.addPriorityHandler(networkMessageHash(), [](Message& message) {
		auto realMessage = message.getMessage<NetworkMessage>();

		if(realMessage) {
		std::cout << "Message is Network\n";
		}
	});*/

	dispatcher.pushMessage(PhysicMessage::create());
	dispatcher.pushMessage(PhysicMessage::create());
	dispatcher.pushMessage(GraphicMessage::create());
	dispatcher.pushMessage(NetworkMessage::create());
	dispatcher.pushMessage(PhysicMessage::create());

	dispatcher.dispatch();

	return 0;
}
