set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if(NOT EIGEN3_INCLUDE_DIR)
    find_package(Eigen3)
endif()

message("Eigen = ${EIGEN3_INCLUDE_DIR}")
set(INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}
    ${EIGEN3_INCLUDE_DIR}
)

include_directories("${INCLUDE_DIR}")
message("include_directories = ${INCLUDE_DIR}")

add_executable(examples main.cpp)

target_compile_options(examples PRIVATE
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-W4>
    $<$<CXX_COMPILER_ID:MSVC>:-W4 -utf-8 -EHsc -bigobj>
)

target_compile_features(examples PRIVATE cxx_std_17)