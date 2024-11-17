cmake_minimum_required(VERSION 3.20)
project(TerreateAudio)
message(STATUS "Project name : " ${PROJECT_NAME})

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "C++ standard : " ${CMAKE_CXX_STANDARD})

function(CloneOpenALSoft)
  message(STATUS "Cloning OpenAL-Soft...")
set(ALSOFT_DLOPEN OFF)
  set(ALSOFT_UTILS OFF)
  set(ALSOFT_EXAMPLES OFF)
  FetchContent_Declare(
    openal_soft
    GIT_REPOSITORY https://github.com/kcat/openal-soft.git
    TAG v1.23.1)
  FetchContent_MakeAvailable(openal_soft)
  message(STATUS "OpenAL-Soft cloned.")
endfunction()

function(CloneTerreateCore)
  message(STATUS "Cloning TerreateCore...")
  set(TERREATECORE_BUILD_TESTS OFF)
  FetchContent_Declare(
    terreate_core
    GIT_REPOSITORY https://github.com/uPiscium/TerreateCore.git
    GIT_TAG main)
  FetchContent_MakeAvailable(terreate_core)
  message(STATUS "TerreateCore cloned.")
endfunction()

function(SetIncludes)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes/deps)
  target_include_directories(${PROJECT_NAME} PUBLIC ../includes)
endfunction()

function(SetLibs)
  cloneterreatecore()
  cloneopenalsoft()
  target_link_libraries(${PROJECT_NAME} PUBLIC TerreateCore)
endfunction()

function(Build)
  add_library(${PROJECT_NAME} STATIC ALHelper.cpp alobj.cpp buffer.cpp context.cpp source.cpp)
  set_target_properties(
    ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
                               LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  setincludes()
  setlibs()
endfunction()

build()
