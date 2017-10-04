add_executable(webExe main.cpp)
target_link_libraries(webExe webLib)

add_custom_command(TARGET webExe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/${CGICC_LIB_PATH}/${CGICC_LIB_NAME}"
    $<TARGET_FILE_DIR:webExe>)
