cmake_minimum_required(VERSION 3.2)

project(SandFallingGame)

set(SOURCES
	src/Cell.cpp
	src/UI.cpp
	src/main.cpp)

set(INCLUDES
	include/Cell.hpp
	include/Common.hpp
	include/UI.hpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(SandFallingGame ${SOURCES} ${INCLUDES})
target_link_libraries(SandFallingGame sfml-graphics sfml-audio)