project(examples)

option(EIGEN_DIR "Eigen directory")
set(INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}
    ${EIGEN_DIR}
)

include_directories("${INCLUDE_DIR}")

add_executable(examples main.cpp)

target_compile_options(examples PRIVATE
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:-W4 -utf-8 -EHsc -bigobj>
)

target_compile_features(examples PRIVATE cxx_std_17)