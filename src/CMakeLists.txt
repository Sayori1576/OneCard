include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(Onecard main.cpp Card.cpp Game.cpp Player.cpp)
set(CMAKE_CXX_STANDARD 20)
target_compile_options(Onecard PUBLIC -Wall -Werror)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

