file(GLOB_RECURSE WEBLIB_BASECLASS_FILES
    "${PROJECT_SOURCE_DIR}/webLib/base_class/*.cpp"
    "${PROJECT_SOURCE_DIR}/webLib/base_class/*.h"
)

source_group("base_class" FILES ${WEBLIB_BASECLASS_FILES})

add_library(webLib ${WEBLIB_BASECLASS_FILES})
target_link_libraries(webLib cgicc)
