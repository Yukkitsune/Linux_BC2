cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(builder)
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/Adapter)
add_executable (monster \${CMAKE_CURRENT_SOURCE_DIR}/Adapter/monster_and_pet.cpp)


