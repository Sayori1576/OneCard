cmake_minimum_required(VERSION 3.0.0)
project(Onecard VERSION 0.1.0)

include(CTest)
enable_testing()
add_subdirectory(src)
add_subdirectory(tests)
include(CPack)
#install(TARGETS Onecard RUNTIME DESTINATION bin)
