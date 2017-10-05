set(GTEST_PATH "${PROJECT_SOURCE_DIR}/third_party/googletest")
set(GMOCK_PATH "${PROJECT_SOURCE_DIR}/third_party/googlemock")
include_directories("${GTEST_PATH}" "${GMOCK_PATH}")
include_directories("${GTEST_PATH}/include" "${GMOCK_PATH}/include")

SET(GTEST_SRC "${GTEST_PATH}/src/gtest-all.cc" "${GTEST_PATH}/src/gtest_main.cc")
SET(GMOCK_SRC "${GMOCK_PATH}/src/gmock-all.cc" "${GMOCK_PATH}/src/gmock_main.cc")

add_library(gtest "${GTEST_SRC}")
add_library(gmock "${GMOCK_SRC}")
find_package (Threads)
target_link_libraries (gtest ${CMAKE_THREAD_LIBS_INIT})


file(GLOB_RECURSE UT_BASECLASS_FILES
    "${PROJECT_SOURCE_DIR}/unit_tests/base_class_tests/*.cpp"
    "${PROJECT_SOURCE_DIR}/unit_tests/base_class_tests/*.h"
)
source_group("base_class_tests" FILES ${UT_BASECLASS_FILES})

file(GLOB_RECURSE UT_FILESMANAGER_FILES
    "${PROJECT_SOURCE_DIR}/unit_tests/files_manager_tests/*.h"
    "${PROJECT_SOURCE_DIR}/unit_tests/files_manager_tests/*.cpp"
)
source_group("files_manager_tests" FILES ${UT_FILESMANAGER_FILES})

file(GLOB_RECURSE UT_MOCKS_FILES
    "${PROJECT_SOURCE_DIR}/unit_tests/mocks/*.h"
    "${PROJECT_SOURCE_DIR}/unit_tests/mocks/*.cpp"
)
source_group("mocks" FILES ${UT_MOCKS_FILES})

add_executable(unitTests ${UT_BASECLASS_FILES} ${UT_FILESMANAGER_FILES} ${UT_MOCKS_FILES})
target_link_libraries(unitTests gtest gmock)
target_link_libraries(unitTests webLib)
