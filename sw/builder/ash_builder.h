#pragma once

#include "ash/ash.h"
#include "builder/sensors/i_sensor_builder.h"
#include "builder/services/i_service_builder.h"
#include "context/i_context_registry.h"
#include "sensors/i_sensor.h"
#include "services/event_service/i_event_service.h"
#include "services/timer_service/i_timer_service.h"

#include <map>

namespace builder
{

class ash_builder 
{
public:
    ash_builder( int argc, char* argv[] );

    ash::ash* build();

private:
    context::i_context* create_context( context::i_updatable* p_updatable, std::string context_name );
    
    void create_sensor_builders();

    void create_service_builders();

    void build_config( const char* path );

    context::i_context_registry* mp_context_registry;

    ::sensors::sensors m_sensors;

    std::map<std::string, sensors::i_sensor_builder*> m_sensor_builders;

    std::map<std::string, services::i_service_builder*> m_service_builders;

    ::services::event_service::i_event_service* mp_event_service;
    
    ::services::timer_service::i_timer_service* mp_timer_service;

};

}

