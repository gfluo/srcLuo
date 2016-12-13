cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER /usr/local/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/local/bin/g++)
add_definitions("-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(forweb)
aux_source_directory(. DIR_SRCS)

add_subdirectory(pushStream)
#add_subdirectory(tool)
#add_subdirectory(tinyXml)
#add_subdirectory(record)
#add_subdirectory(connDb)
add_executable(streamServer1.0.1 ${DIR_SRCS})

target_link_libraries(streamServer1.0.1
		      avformat
		      avcodec
		      avutil
		      CPushStream
                      boost_system
                      boost_filesystem
                      boost_thread
                      )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
