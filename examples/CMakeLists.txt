project(examples)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(examples main.cpp)

target_compile_options(examples PRIVATE
    $<$<CONFIG:Release>:-O2 -DNDEBUG>
    $<$<CXX_COMPILER_ID:GNU>:-Wall>
    $<$<CXX_COMPILER_ID:Clang>:-Wall>
    $<$<CXX_COMPILER_ID:MSVC>:-W4 -bigobj>
)

target_compile_features(examples PRIVATE cxx_std_14)