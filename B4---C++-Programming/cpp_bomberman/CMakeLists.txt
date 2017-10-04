cmake_minimum_required(VERSION 3.2)
project(cpp_bomberman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++11")

include_directories(${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/lib/lua/include)

set(SOURCE_FILES
 #   src/etattest.cpp
 #   src/GameEngine.cpp
    src/main.cpp
    src/others/Score.cpp
    src/others/GenerateMaze.cpp
    src/botme/Lua.cpp)

set(LIB_FILE
		lib/lua/lib/liblua.a)

add_executable(cpp_bomberman ${SOURCE_FILES} ${LIB_FILE})
link_directories(/home/ankirama/rendu/cpp_bomberman/lib/lua/include)

add_executable(cpp_bomberman ${SOURCE_FILES})

target_link_libraries(cpp_bomberman
                      /home/ankirama/rendu/cpp_bomberman/lib/lua/lib/liblua.a)
