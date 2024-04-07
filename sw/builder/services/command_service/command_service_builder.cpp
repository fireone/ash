#include "command_service_builder.h"
#include "services/command_service/command_service.h"
#include "services/command_service/joystick_command_provider.h"

#include <iostream>

namespace builder
{

namespace services
{

namespace command_service
{

command_service_builder::command_service_builder( ::services::event_service::i_event_service* p_event_service )
: m_service_name( "command_service" )
, mp_event_service( p_event_service )
{
}

::services::i_service* command_service_builder::build( const parameter_list& parameters )
{
    std::cout << "command_service_builder" << std::endl;

    ::services::command_service::joystick_command_provider* p_joystick = 
        new ::services::command_service::joystick_command_provider;

    return new ::services::command_service::command_service( mp_event_service,
                                                             p_joystick );
}

const std::string& command_service_builder::get_service_name() const
{
    return m_service_name;
}

}

}

}