cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Gomoku)

set(SOURCE_FILES
        src/core/main.cpp
        src/graphic/IntroState.cpp
        src/core/GameEngine.cpp
        src/arbiter/Arbiter.cpp
        src/tests/CoreFirstRuleTests.cpp
        src/tests/CoreWinnerTests.cpp
        src/tests/CoreSecondRuleTests.cpp
        src/tests/SpeedTests.cpp
        src/graphic/Wallpaper.cpp
        src/graphic/Stats.cpp
        src/arbiter/Map.cpp src/ai/AI.cpp)

find_package(Qt5Widgets REQUIRED)

include_directories(include/core
        include/ai
        include/graphic
        include/tests
        include/arbiter
        include
        assets)

set(HW_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${HW_HEADER_DIR})

qt5_wrap_cpp(Gomoku_SRC ${HW_HEADER_DIR}/core/GameEngine.h
        ${HW_HEADER_DIR}/graphic/IntroState.h
        ${HW_HEADER_DIR}/graphic/Wallpaper.h
        ${HW_HEADER_DIR}/graphic/Stats.h)

qt5_wrap_ui(Gomoku_UI
        ${HW_HEADER_DIR}/ui/dialog.ui
        ${HW_HEADER_DIR}/ui/mainwindow.ui
        ${HW_HEADER_DIR}/ui/wallpaper.ui
        ${HW_HEADER_DIR}/ui/stats.ui)

add_executable(Gomoku ${SOURCE_FILES} ${Gomoku_SRC} ${Gomoku_UI} )

qt5_use_modules(Gomoku Widgets)