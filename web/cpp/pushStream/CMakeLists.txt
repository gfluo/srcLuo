cmake_minimum_required(VERSION 2.8)

#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(forweb)

aux_source_directory(. DIR_PUSH)

add_library(CPushStream ${DIR_PUSH})

#target_link_libraries()
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


