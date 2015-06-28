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

#include <string>
#include <memory>
#include <functional>

inline const std::size_t graphicMessageHash() {
	return std::hash<std::string>()("GraphicMessage");
}

inline const std::size_t physicMessageHash() {
	return std::hash<std::string>()("PhysicMessage");
}

inline const std::size_t networkMessageHash() {
	return std::hash<std::string>()("NetworkMessage");
}

struct Message {
	template<class T>
	T* getMessage() {
		return dynamic_cast<T*>(this);
	}
	
	virtual const std::string name() const = 0;
	virtual const std::size_t hash() const = 0;
};

typedef std::unique_ptr<Message> MessagePtr;

struct GraphicMessage 
	: public Message {

	static std::unique_ptr<Message> create() {
		auto message = std::make_unique<GraphicMessage>();

		return std::move(message);
	}

	const std::string name() const {
		return "graphic";
	}

	const std::size_t hash() const {
		return graphicMessageHash();
	}
};

struct PhysicMessage
	: public Message {

	static std::unique_ptr<Message> create() {
		auto message = std::make_unique<PhysicMessage>();

		return std::move(message);
	}

	const std::string name() const {
		return "physic";
	}

	const std::size_t hash() const {
		return physicMessageHash();
	}
};

struct NetworkMessage
	: public Message {

	static std::unique_ptr<Message> create() {
		auto message = std::make_unique<NetworkMessage>();

		return std::move(message);
	}

	const std::string name() const {
		return "network";
	}

	const std::size_t hash() const {
		return networkMessageHash();
	}
};