cmake_minimum_required(VERSION 3.20)
option(TERREATEAUDIO_BUILD_TESTS "Build tests" ON)

add_subdirectory(impls)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fsanitize=address")

if(TERREATEAUDIO_BUILD_TESTS)
  add_subdirectory(tests)
endif()
