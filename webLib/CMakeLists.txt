file(GLOB_RECURSE WEBLIB_BASECLASS_FILES
    "${PROJECT_SOURCE_DIR}/webLib/base_class/*.cpp"
    "${PROJECT_SOURCE_DIR}/webLib/base_class/*.h"
)
source_group("base_class" FILES ${WEBLIB_BASECLASS_FILES})

file(GLOB_RECURSE WEBLIB_FILESMANAGER_FILES
    "${PROJECT_SOURCE_DIR}/webLib/files_manager/files_manager_${OS_TYPE}.cpp"
    "${PROJECT_SOURCE_DIR}/webLib/files_manager/files_manager.h"
    "${PROJECT_SOURCE_DIR}/webLib/files_manager/files_manager.cpp"
)
source_group("files_manager" FILES ${WEBLIB_FILESMANAGER_FILES})

file(GLOB_RECURSE WEBLIB_HELPERS_FILES
    "${PROJECT_SOURCE_DIR}/webLib/helpers/*.h"
)
source_group("helpers" FILES ${WEBLIB_HELPERS_FILES})

add_library(webLib ${WEBLIB_BASECLASS_FILES} ${WEBLIB_FILESMANAGER_FILES} ${WEBLIB_HELPERS_FILES})
target_link_libraries(webLib cgicc)
