###
# Seeker
#
# The 2D ADV Game Frameworks written in C++ and mruby.
#
# @author Aotokitsuruya
###

cmake_minimum_required(VERSION 3.6)

project(Seeker)

# Enable YCM autocomplete
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

# Paths
set(SRC_DIR src)
set(LIB_DIR lib)
set(INC_DIR include)

# Flags
set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall -Werror")

# Header Files
include_directories(${INC_DIR})

# Load other directory
add_subdirectory(${LIB_DIR})
add_subdirectory(${SRC_DIR})

