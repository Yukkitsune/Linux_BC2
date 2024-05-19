cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(builder)
include_directories(Adapter)
add_executable (monster Adapter/monster_and_pet.cpp)


