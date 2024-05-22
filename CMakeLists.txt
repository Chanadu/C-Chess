cmake_minimum_required(VERSION 3.0.0)
project(C-Chess VERSION 0.1.0 LANGUAGES C)

include(CTest)
include_directories(. ./lib)
enable_testing()

# file(GLOB sources CONFIGURE_DEPENDS *.h *.c utils/*.c utils/*.h)
add_executable(C-Chess main.c lib/utils.h lib/make_move.c lib/make_move.h lib/print_board.c lib/print_board.h lib/get_move_input.c lib/get_move_input.h)
# target_include_directories()
# add_executable(C-Chess main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
