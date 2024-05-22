cmake_minimum_required(VERSION 3.0.0)
project(C-Chess VERSION 0.1.0 LANGUAGES C)

add_definitions("-Wall" "-g")

include(CTest)
enable_testing()

add_library(HEADER-ONLY INTERFACE)
add_library(PROJECTLIB INTERFACE)

target_include_directories(HEADER-ONLY INTERFACE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(PROJECTLIB INTERFACE ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(HEADER-ONLY INTERFACE PROJECTLIB)


add_executable(C-Chess main.c)
target_link_libraries(C-Chess PRIVATE HEADER-ONLY)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)