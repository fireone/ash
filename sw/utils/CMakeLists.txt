project( utils )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST}
   geo_pos.cpp
   uuid.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )

