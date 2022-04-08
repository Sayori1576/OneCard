include_directories(${CMAKE_SOURCE_DIR}/include)
set(SRCS  main.cpp Card.cpp Game.cpp Player.cpp GlCard.cpp Nstatus.cpp Score.cpp textglinoutput.cpp textgminoutput.cpp)
#add_executable(Onecard ${SRCS})
add_library(OneCard_lib Card.cpp GlCard.cpp)
target_link_libraries(OneCard_lib effolkronium_random)
#target_compile_options(OneCard_lib PUBLIC -Wall -Werror)
target_compile_options(OneCard_lib PUBLIC -Wall -Werror)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

