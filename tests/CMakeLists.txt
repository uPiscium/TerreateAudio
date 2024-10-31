cmake_minimum_required(VERSION 3.20)
project(TATest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(SetLibs)
  target_link_libraries(${PROJECT_NAME} TerreateAudio)
endfunction()

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes/deps)
  target_include_directories(${PROJECT_NAME} PUBLIC ../tests/deps)
endfunction()

function(Build)
  add_executable(${PROJECT_NAME} TATest.cpp)
  set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                   ${CMAKE_BINARY_DIR}/bin)
  setlibs()
  setincludes()
endfunction()

build()
