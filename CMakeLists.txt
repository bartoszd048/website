cmake_minimum_required(VERSION 2.8.9)
project (Website)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CGICC_PATH "third_party/cgicc")
if(WIN32)
    set(CGICC_LIB_NAME "cgicc.dll")
    set(CGICC_LIB_PATH "${CGICC_PATH}/bin/windows")
else()
    set(CGICC_LIB_NAME "libcgicc.so")
    set(CGICC_LIB_PATH "${CGICC_PATH}/bin/linux")
endif()

link_directories("${CGICC_LIB_PATH}")
include_directories("${CGICC_PATH}")


add_executable(website main.cpp)
target_link_libraries(website cgicc)

add_custom_command(TARGET website POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/${CGICC_LIB_PATH}/${CGICC_LIB_NAME}"
    $<TARGET_FILE_DIR:website>)
