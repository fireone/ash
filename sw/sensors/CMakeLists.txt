project( sensors )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST}
   gnss/ublox_zed_f9r.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )

