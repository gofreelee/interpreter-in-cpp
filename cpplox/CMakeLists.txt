cmake_minimum_required(VERSION 3.10)

project(cpplox VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
file(GLOB PARSER ${CMAKE_CURRENT_SOURCE_DIR}/parser/*.cc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ast)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/parser)

add_executable(cpplox ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${PARSER})