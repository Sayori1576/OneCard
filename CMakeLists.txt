cmake_minimum_required(VERSION 3.0.0)
project(Onecard VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Onecard main.cpp Card.cpp Game.cpp Player.cpp)
set(CMAKE_CXX_STANDARD 20)
target_compile_options(Onecard PUBLIC -Wall -Werror)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
