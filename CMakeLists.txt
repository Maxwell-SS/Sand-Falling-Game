# Define what minimum version of CMake is required
# We're using some rather modern features here,
# so we've gone with 3.1.x
cmake_minimum_required(VERSION 3.2)

# Give the project a name
project(SandFallingGame)

# Set all of the source code that this project will use
set(SOURCES
	src/Cell.cpp
	src/UI.cpp
	src/main.cpp)

# Show cmake all of the include files that we're using
set(INCLUDES
	include/Cell.hpp
	include/Common.hpp
	include/UI.hpp)

# Find version 2.5 of the SFML library, including the necessary modules
# The files for SFML aren't included in the repository, so for the best results:
# Windows: C:\Program Files\SFML-2.5.0
# Linux: Build SFML yourself, then generate. If that doesn't work,
#        then set SFML_DIR to the location of your install and try again
# Mac: ...
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Add the include directory into the linker, so the header files can be found
include_directories(${PROJECT_SOURCE_DIR}/include)

# Tell the compiler where the source code is, and add it to the executable
add_executable(SandFallingGame ${SOURCES} ${INCLUDES})

# Add the following SFML modules to the application:
target_link_libraries(SandFallingGame sfml-graphics sfml-audio)