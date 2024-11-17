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

function(PostProcess)
  if(WIN32)
    add_custom_command(
      TARGET ${PROJECT_NAME}
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:OpenAL>/OpenAL32.dll
              $<TARGET_FILE_DIR:${PROJECT_NAME}>)
  else()
    add_custom_command(
      TARGET ${PROJECT_NAME}
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:OpenAL>/libopenal.so
              $<TARGET_FILE_DIR:${PROJECT_NAME}>/)
  endif()
endfunction()

function(Build)
  add_executable(${PROJECT_NAME} TATest.cpp)
  set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                   ${CMAKE_BINARY_DIR}/bin)
  setlibs()
  setincludes()
  postprocess()
endfunction()

build()
