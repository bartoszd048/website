add_executable(webExe main.cpp)
target_link_libraries(webExe webLib)

if(MSVC)
    target_compile_options(webExe PUBLIC "/wd4251")
endif()

add_custom_command(TARGET webExe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${PROJECT_SOURCE_DIR}/${CGICC_LIB_PATH}/${CGICC_LIB_NAME}"
    $<TARGET_FILE_DIR:webExe>)
