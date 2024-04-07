project( services )

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST}
    command_service/command_service.cpp
    command_service/joystick_command_provider.cpp
    event_sender_service/event_sender_service.cpp
    event_sender_service/event_sender_events.cpp
    event_service/event_service.cpp
    navigation_service/navigation_service.cpp
    navigation_service/navigation_events.cpp
    timer_service/timer_service.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries( services LINK_PUBLIC context )
target_link_libraries( services LINK_PUBLIC command )
