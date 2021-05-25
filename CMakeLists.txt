cmake_minimum_required(VERSION 3.2)

project(SandFallingGame)

set(SOURCES
	src/UI.cpp
	src/Grid.cpp
	src/main.cpp
	src/Misc.cpp
	src/Elements/Sand.cpp
	src/Elements/Wall.cpp
	src/Elements/Stone.cpp
	src/Elements/Water.cpp)

set(INCLUDES
	include/Elements.hpp
	include/Common.hpp
	include/UI.hpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(SandFallingGame ${SOURCES} ${INCLUDES})
target_link_libraries(SandFallingGame sfml-graphics sfml-audio)