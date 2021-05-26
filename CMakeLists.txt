cmake_minimum_required(VERSION 3.2)

project(SandFallingGame)

set(INCLUDES
	include/Elements.hpp
	include/Common.hpp
	include/UI/UI.hpp)

set(SOURCES
	src/Grid.cpp
	src/main.cpp
	src/Misc.cpp
	src/Logic.cpp
	src/UI/UI.cpp
	src/Elements/None.cpp
	src/Elements/Sand.cpp
	src/Elements/Wall.cpp
	src/Elements/Stone.cpp
	src/Elements/Water.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(SandFallingGame ${SOURCES} ${INCLUDES})
target_link_libraries(SandFallingGame sfml-graphics sfml-audio)