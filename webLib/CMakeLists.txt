set(WEBLIB_SRC "hw.cpp" "hw.h")

add_library(webLib ${WEBLIB_SRC})
target_link_libraries(webLib cgicc)
