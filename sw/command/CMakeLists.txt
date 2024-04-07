project( command )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST}
   cutter_command.cpp
   move_command.cpp
   panic_command.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )

