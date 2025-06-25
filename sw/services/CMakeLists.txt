project( services )

if(BUILD_FOR_DESKTOP)
    set(CMAKE_AUTOMOC ON)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)
endif()

set(SRC_LIST
    command_service/command_service.h command_service/command_service.cpp
    command_service/joystick_command_provider.h command_service/joystick_command_provider.cpp
    event_sender_service/event_sender_service.h event_sender_service/event_sender_service.cpp
    event_sender_service/event_sender_events.h event_sender_service/event_sender_events.cpp
    event_service/event_service.h event_service/event_service.cpp
    navigation_service/navigation_service.h navigation_service/navigation_service.cpp
    navigation_service/navigation_events.cpp navigation_service/navigation_events.cpp
    route_service/route_service.h route_service/route_service.cpp
    route_service/route_events.h route_service/route_events.cpp
    timer_service/timer_service.h timer_service/timer_service.cpp
)

if(BUILD_FOR_DESKTOP)
    list(APPEND SRC_LIST
        simulator_service/simulator_events.h simulator_service/simulator_events.cpp
        simulator_service/simulator_service.h simulator_service/simulator_service.cpp
        simulator_service/environment/i_environment.h
        simulator_service/environment/environment.h simulator_service/environment/environment.cpp
        simulator_service/gui/MainWindow.h simulator_service/gui/MainWindow.cpp
        simulator_service/gui/GridMapView.h simulator_service/gui/GridMapView.cpp
        simulator_service/gui/SimView.h simulator_service/gui/SimView.cpp
        simulator_service/robot/simulated_robot.h simulator_service/robot/simulated_robot.cpp
    )
endif()

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.. )

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC context command )
target_link_libraries(${PROJECT_NAME} INTERFACE robot )

if(BUILD_FOR_DESKTOP)
    target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Widgets)
endif()



