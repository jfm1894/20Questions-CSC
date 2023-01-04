cmake_minimum_required(VERSION 3.1...3.14) 
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(20q VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
  main.cpp
  tree.h
  twentyq.h twentyq.cpp
)

file (COPY data.txt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

