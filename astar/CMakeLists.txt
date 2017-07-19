cmake_minimum_required(VERSION 3.2.2)

project(astar)

set(astar_HEADERS
		Node.h
		Area.h
		)

set(astar_SOURCES
		Node.cpp
		Area.cpp
		)

add_library(astar ${astar_SOURCES} ${astar_HEADERS})
