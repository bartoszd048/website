set(GTEST_PATH "${PROJECT_SOURCE_DIR}/third_party/googletest")
include_directories("${GTEST_PATH}")
include_directories("${GTEST_PATH}/include")

SET(GTEST_SRC "${GTEST_PATH}/src/gtest-all.cc" "${GTEST_PATH}/src/gtest_main.cc")
add_library(gtest "${GTEST_SRC}")
find_package (Threads)
target_link_libraries (gtest ${CMAKE_THREAD_LIBS_INIT})

add_executable(unitTests test1.cpp)
target_link_libraries(unitTests gtest)