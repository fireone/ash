project( ash_lib )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST}
   ash.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

