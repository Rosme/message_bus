#
# Copyright (c) 2015 Jean-Sébastien Fauteux
#
# This software is provided 'as-is', without any express or implied warranty. 
# In no event will the authors be held liable for any damages arising from 
# the use of this software.
#
# Permission is granted to anyone to use this software for any purpose, 
# including commercial applications, and to alter it and redistribute it freely, 
# subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not claim 
#    that you wrote the original software. If you use this software in a product, 
#    an acknowledgment in the product documentation would be appreciated but is
#    not required.
#
# 2. Altered source versions must be plainly marked as such, and must not be 
#    misrepresented as being the original software.
#
# 3. This notice may not be removed or altered from any source distribution.
#
cmake_minimum_required(VERSION 2.8)

project(MessageBus)

include_directories(include)

if(UNIX)
	include(CheckCXXCompilerFlag)
	check_cxx_compiler_flag("-std=c++1y" COMPILER_SUPPORTS_CXX1Y)
	check_cxx_compiler_flag("-std=c++14" COMPILER_SUPPORTS_CXX14)
	check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
	check_cxx_compiler_flag("-std=c++0X" COMPILER_SUPPORTS_CXX0X)
	if(COMPILER_SUPPORTS_CXX1Y)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
	elseif(COMPILER_SUPPORTS_CXX14)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
	elseif(COMPILER_SUPPORTS_CXX11)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	elseif(COMPILER_SUPPORTS_CXX0X)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	endif()
endif()

SET(SRC
	src/message_dispatcher.cpp
	src/message_handler.cpp
	src/main.cpp
	)

SET(INC
	include/message_dispatcher.hpp
	include/message_handler.hpp
	include/message.hpp
	)

add_executable(MessageBus ${SRC} ${INC})
