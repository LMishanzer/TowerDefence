cmake_minimum_required(VERSION 3.16)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 14)

add_executable(TowerDefence src/main.cpp src/CMap.cpp src/CMap.h src/CEnemy.cpp src/CEnemy.h src/CRoute.h src/CRoute.cpp)