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

#include <algorithm>

void MessageDispatcher::pushMessage(MessagePtr message, bool isPriority) {
	if(isPriority) {
		auto fn = m_priorityHandler.find(message->hash());

		if(fn != m_priorityHandler.end()) {
			fn->second(*message);
			return;
		}
	}
	m_messages.push(std::move(message));
}

void MessageDispatcher::addHandler(MessageHandler* handler) {
	m_handlers.push_back(handler);
}

void MessageDispatcher::removeHandler(MessageHandler* handler) {
	const auto it = std::find(m_handlers.begin(), m_handlers.end(), handler);
	if(it != m_handlers.end()) {
		m_handlers.erase(it);
	}
}

void MessageDispatcher::addPriorityHandler(std::size_t hash, std::function<void(Message&)> handlerFunction) {
	m_priorityHandler[hash] = handlerFunction;
}

void MessageDispatcher::dispatch() {
	while(!m_messages.empty()) {
		Message& message = *m_messages.front().get();
		for(auto handler : m_handlers) {
			handler->onMessage(message);
		}
		m_messages.pop();
	}
}
