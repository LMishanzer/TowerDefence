cmake_minimum_required(VERSION 3.16)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 14)

add_executable(TowerDefence src/main.cpp src/sources/CMap.cpp src/headers/CMap.h src/sources/CEnemy.cpp src/headers/CEnemy.h
        src/headers/CRoute.h src/sources/CRoute.cpp src/headers/CEnemiesGenerator.h src/sources/CEnemiesGenerator.cpp src/headers/CLevel.h src/sources/CLevel.cpp
        src/headers/GameOver.h src/headers/CTower.h src/sources/CTower.cpp src/headers/CBullet.h src/headers/CGameObject.h
        src/sources/CBullet.cpp)