cmake_minimum_required (VERSION 3.8)

project (ADAPT-FMP)

add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/utf-8>)

option(REGENERATE_CODES "regenerate parser, lexer and function codes" OFF)
option(BUILD_TEST "build test program" OFF)

if (REGENERATE_CODES)
    add_subdirectory(FMPGenerator)
endif ()

if (BUILD_TEST)
    add_subdirectory (examples)
endif ()