project( robot )

add_library( ${PROJECT_NAME} STATIC 
   i_robot.h
   abstract_robot.h abstract_robot.cpp
   robot.h robot.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )
