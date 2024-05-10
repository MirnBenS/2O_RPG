cmake_minimum_required(VERSION 3.27)
project(2O_RPG)

set(CMAKE_CXX_STANDARD 17)

include_directories(Character)
include_directories(Combat)
include_directories(Enemy)
include_directories(Player)

add_executable(2O_RPG
        main.cpp
        Character/Character.cpp
        Character/Character.h
        Enemy/Enemy.cpp
        Enemy/Enemy.h
        Player/Player.cpp
        Player/Player.h
        Combat/Combat.cpp
        Combat/Combat.h
        Utils.h
        Combat/Action.h
        Utils.h)
