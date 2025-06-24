#include "ash_builder.h"
#include "ash_arg_handler.h"

#include "context/context_registry.h"

#include "services/event_service/event_service.h"
#include "services/timer_service/timer_service.h"

#include "sensors/gnss/dummy_gnss_builder.h"
#include "sensors/gnss/ublox_zed_f9r_builder.h"

#include "services/command_service/command_service_builder.h"
#include "services/event_sender_service/event_sender_service_builder.h"
#include "services/navigation_service/navigation_service_builder.h"
#include "services/route_service/route_service_builder.h"
#include "services/simulator_service/simulator_service_builder.h"

#include <iostream>

#include "pugixml.hpp"

namespace builder
{

ash_builder::ash_builder( int argc, char* argv[] )
: mp_context_registry( new context::context_registry )
, m_sensors()
, m_sensor_builders()
, m_service_builders()
, mp_event_service( new ::services::event_service::event_service )
, mp_timer_service( new ::services::timer_service::timer_service )
{
    ash_arg_handler::parse_arguments( argc, argv );
}

ash::ash *ash_builder::build()
{    
    context::contexts contexts;

    create_sensor_builders();
    create_service_builders();
   
    mp_context_registry->register_context( "EVENT_SERVICE_CONTEXT" )->add_updatable( mp_event_service );
    mp_context_registry->register_context( "TIMER_SERVICE_CONTEXT" )->add_updatable( mp_timer_service );   

    build_config( ash_arg_handler::config_file().c_str() );

    return new ash::ash( mp_context_registry, m_sensors );
}

context::i_context* ash_builder::create_context( context::i_updatable* p_updatable, std::string context_name )
{
    context::i_context* p_context = mp_context_registry->register_context( context_name );

    p_context->add_updatable( p_updatable );
    
    return p_context;
}

void ash_builder::create_sensor_builders()
{
    sensors::i_sensor_builder* p_dummy_gnss_builder = new sensors::gnss::dummy_gnss_builder;
    sensors::i_sensor_builder* p_ublox_zed_f9r_builder = new sensors::gnss::ublox_zed_f9r_builder;
    
    m_sensor_builders[ p_dummy_gnss_builder->get_sensor_name() ] = p_dummy_gnss_builder;
    m_sensor_builders[ p_ublox_zed_f9r_builder->get_sensor_name() ] = p_ublox_zed_f9r_builder;
}

void ash_builder::create_service_builders()
{
    services::i_service_builder* p_command_service_builder = 
        new services::command_service::command_service_builder( mp_event_service );
        
    services::i_service_builder* p_event_sender_service_builder = 
        new services::event_sender_service::event_sender_service_builder( mp_event_service, mp_timer_service );

    services::i_service_builder* p_navigation_service_builder = 
        new services::navigation_service::navigation_service_builder( mp_event_service );

    services::i_service_builder* p_route_service_builder =
        new services::route_service::route_service_builder( mp_event_service );

    services::i_service_builder* p_simulator_service_builder =
        new services::simulator_service::simulator_service_builder( mp_event_service );

    m_service_builders[ p_command_service_builder->get_service_name() ] = p_command_service_builder;
    m_service_builders[ p_event_sender_service_builder->get_service_name() ] = p_event_sender_service_builder;
    m_service_builders[ p_navigation_service_builder->get_service_name() ] = p_navigation_service_builder;
    m_service_builders[ p_route_service_builder->get_service_name() ] = p_route_service_builder;
    m_service_builders[ p_simulator_service_builder->get_service_name() ] = p_simulator_service_builder;
}

void ash_builder::build_config( const char* path )
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file( path );

    //parse sensors
    for( pugi::xml_node sensors: doc.child( "config" ).child( "sensors" ) )
    {
        sensors::parameter_list params;

        for( pugi::xml_node param: sensors ) 
        {
            params[ param.name() ] = param.child_value();
        }                
        
        try
        {
            m_sensors.push_back( m_sensor_builders.at( sensors.child_value( "name" ) )->build( params, mp_context_registry ) );
        }
        catch( const std::out_of_range& oor )
        {
            std::cout << "Exception when building sensor: " 
                      << sensors.child_value( "name" ) 
                      << "."
                      << std::endl
                      << "Exception: "
                      << oor.what()
                      << std::endl;
        }
    }   

    //parse services
    for( pugi::xml_node services: doc.child( "config" ).child( "services" ) )
    {
        sensors::parameter_list params;

        for( pugi::xml_node param: services ) 
        {
            params[ param.name() ] = param.child_value();
        }                
        
        try
        {
            create_context( m_service_builders.at( services.child_value( "name" ) )->build( params ),  services.child_value( "name" ) );
        }
        catch( const std::out_of_range& oor )
        {
            std::cout << "Exception when building service: " 
                      << services.child_value( "name" ) 
                      << "."
                      << std::endl
                      << "Exception: "
                      << oor.what()
                      << std::endl;
        }
    }   
}

}

