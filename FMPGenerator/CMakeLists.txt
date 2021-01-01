set(LEMON_EXE_PATH "NOT_SET" CACHE FILEPATH "lemon executable path")
set(RE2C_EXE_PATH "NOT_SET" CACHE FILEPATH "re2c executable path")

find_package(Python)

set(FMP_DETAIL_DIR    ${CMAKE_SOURCE_DIR}/ADAPT/FMP/Detail)
set(GENERATOR_DIR     ${CMAKE_SOURCE_DIR}/FMPGenerator)
set(FMPLEMON_PARSER_Y FMPLemon_parser.y)
set(FMPLEMON_PARSER_C ${FMP_DETAIL_DIR}/FMPLemon_parser.c)
set(FMPLEMON_PARSER_H ${FMP_DETAIL_DIR}/FMPLemon_parser.h)
set(FMPRE2C_IMPL_B_H  FMPRe2c_impl_b.h)
set(FMPRE2C_IMPL_H    ${FMP_DETAIL_DIR}/FMPRe2c_impl.h)
set(FMPNODE_FUNC_H    ${FMP_DETAIL_DIR}/FMPNode_func.h)
set(FMPFUNCTION_H     ${FMP_DETAIL_DIR}/FMPFunction.h)
set(GENERATE_PY       ${GENERATOR_DIR}/Generate.py)

if (WIN32)
    set(CYGWIN_PATH "NOT_SET" CACHE PATH "cygwin path")
    string(REGEX REPLACE "/" "\\\\" FMP_DETAIL_DIR ${FMP_DETAIL_DIR})
    string(REGEX REPLACE "/" "\\\\" FMPLEMON_PARSER_Y ${FMPLEMON_PARSER_Y})
    string(REGEX REPLACE "/" "\\\\" FMPLEMON_PARSER_C ${FMPLEMON_PARSER_C})
    string(REGEX REPLACE "/" "\\\\" FMPLEMON_PARSER_H ${FMPLEMON_PARSER_H})
    string(REGEX REPLACE "/" "\\\\" FMPRE2C_IMPL_B_H ${FMPRE2C_IMPL_B_H})
    string(REGEX REPLACE "/" "\\\\" FMPRE2C_IMPL_H ${FMPRE2C_IMPL_H})
    string(REGEX REPLACE "/" "\\\\" FMPNODE_FUNC_H ${FMPNODE_FUNC_H})
    string(REGEX REPLACE "/" "\\\\" FMPFUNCTION_H ${FMPFUNCTION_H})
    string(REGEX REPLACE "/" "\\\\" GENERATE_PY ${GENERATE_PY})
    string(REGEX REPLACE "/" "\\\\" GENERATOR_DIR ${GENERATOR_DIR})
    string(REGEX REPLACE "/" "\\\\" CYGWIN_PATH ${CYGWIN_PATH})
    set(CYGWIN_PATH_SEMICOLON "${CYGWIN_PATH};")
else()
    set(CYGWIN_PATH_SEMICOLON "")
endif ()

if (MSVC)
    set(RE2C_LOC_FORMAT msvc)
else()
    set(RE2C_LOC_FORMAT gnu)
endif()

add_custom_command(OUTPUT
                       ${FMPLEMON_PARSER_Y}
                       ${FMPNODE_FUNC_H}
                       ${FMPFUNCTION_H}
                   COMMAND
                       ${Python} "${GENERATE_PY}" "${FMP_DETAIL_DIR}" "${GENERATOR_DIR}"
                   WORKING_DIRECTORY
                       ${CMAKE_SOURCE_DIR}/FMPGenerator)
add_custom_target(GEN_FMP_LEMON_PARSER_Y
                  DEPENDS
                      ${FMPLEMON_PARSER_Y})

add_custom_command(OUTPUT
                       ${FMPRE2C_IMPL_H}
                   COMMAND
                       ${CMAKE_COMMAND} -E env "PATH=${CYGWIN_PATH_SEMICOLON}$ENV{PATH}"
                       "${RE2C_EXE_PATH}" "-i" "--location-format" "${RE2C_LOC_FORMAT}" "--no-generation-date" "--no-version"
                       "-o" "${FMPRE2C_IMPL_H}" "-W" "${FMPRE2C_IMPL_B_H}"
                   WORKING_DIRECTORY
                       ${CMAKE_SOURCE_DIR}/FMPGenerator)
add_custom_command(OUTPUT
                       ${FMPLEMON_PARSER_C}
                       ${FMPLEMON_PARSER_H}
                   DEPENDS
                       GEN_FMP_LEMON_PARSER_Y
                   COMMAND
                       ${CMAKE_COMMAND} -E env "PATH=${CYGWIN_PATH_SEMICOLON}$ENV{PATH}"
                       "${LEMON_EXE_PATH}" "-d${FMP_DETAIL_DIR}" "${FMPLEMON_PARSER_Y}"
                   WORKING_DIRECTORY
                       ${CMAKE_SOURCE_DIR}/FMPGenerator)

add_custom_target(generate ALL
                  DEPENDS
                      ${FMPNODE_FUNC_H}
                      ${FMPFUNCTION_H}
                      ${FMPRE2C_IMPL_H}
                      ${FMPLEMON_PARSER_C}
                      ${FMPLEMON_PARSER_H})