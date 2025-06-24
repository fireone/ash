project( builder )

set(SRC_LIST
   ash_builder.cpp
   ash_arg_handler.cpp
   sensors/gnss/dummy_gnss_builder.cpp
   sensors/gnss/ublox_zed_f9r_builder.cpp
   services/command_service/command_service_builder.cpp
   services/event_sender_service/event_sender_service_builder.cpp
   services/navigation_service/navigation_service_builder.cpp
   services/route_service/route_service_builder.cpp
)

if(BUILD_FOR_DESKTOP)
    list(APPEND SRC_LIST services/simulator_service/simulator_service_builder.cpp )
endif()


add_library( ${PROJECT_NAME} STATIC ${SRC_LIST} )

target_include_directories( ${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries( builder LINK_PRIVATE pugixml )
target_link_libraries( builder LINK_PUBLIC ash_lib )
target_link_libraries( builder LINK_PUBLIC services )
target_link_libraries( builder LINK_PUBLIC utils )
target_link_libraries( builder LINK_PUBLIC sensors )
