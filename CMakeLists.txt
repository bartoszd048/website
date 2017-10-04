cmake_minimum_required(VERSION 2.8.9)
project (Website)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "release" CACHE STRING "Set default CMAKE_BUILD_TYPE" FORCE)
endif()
STRING(TOLOWER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CGICC_PATH "third_party/cgicc")
if(WIN32)
    set(CGICC_LIB_NAME "cgicc.dll")
    set(CGICC_LIB_PATH "${CGICC_PATH}/bin/windows")
else()
    set(CGICC_LIB_NAME "libcgicc.so")
    set(CGICC_LIB_PATH "${CGICC_PATH}/bin/linux}")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "debug")
    set(CGICC_LIB_PATH "${CGICC_LIB_PATH}/debug")
else()
    set(CGICC_LIB_PATH "${CGICC_LIB_PATH}/release")
endif()

link_directories("${CGICC_LIB_PATH}")
include_directories("third_party")


add_executable(website main.cpp)
target_link_libraries(website cgicc)

add_custom_command(TARGET website POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/${CGICC_LIB_PATH}/${CGICC_LIB_NAME}"
    $<TARGET_FILE_DIR:website>)
