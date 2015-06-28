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
#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <map>
#include <string>
#include <functional>

#include "message.hpp"

class MessageHandler;

class MessageDispatcher {
public:
	MessageDispatcher() = default;

	MessageDispatcher(const MessageDispatcher&) = delete;
	MessageDispatcher& operator=(const MessageDispatcher&) = delete;

	void pushMessage(MessagePtr message, bool isPriority = true);
	void dispatch();

	void addHandler(MessageHandler* handler);
	void removeHandler(MessageHandler* handler);
	
	void addPriorityHandler(std::size_t hash, std::function<void(Message&)> handlerFunction);

private:
	std::vector<MessageHandler*> m_handlers;
	std::map<std::size_t, std::function<void(Message&)>> m_priorityHandler;
	std::queue<MessagePtr> m_messages;
};