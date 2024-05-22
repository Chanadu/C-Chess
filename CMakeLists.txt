cmake_minimum_required(VERSION 3.0.0)
project(C-Chess VERSION 0.1.0 LANGUAGES C)

include(CTest)
include_directories(. ./utils)
enable_testing()

# file(GLOB sources CONFIGURE_DEPENDS *.h *.c utils/*.c utils/*.h)
add_executable(C-Chess main.c utils/utils.h utils/make_move.c utils/make_move.h utils/print_board.c utils/print_board.h)
# target_include_directories()
# add_executable(C-Chess main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
