#include "command_service.h"

#include "command/cutter_command.h"
#include "command/move_command.h"
#include "command/cutter_command.h"

#include <iostream>

namespace services
{

namespace command_service
{

command_service::command_service( event_service::i_event_service* p_event_service,
                                  command::i_command_provider*    p_joystick_command_provider )
: m_name( "command_service" )
, mp_event_service( p_event_service )
, mp_joystick_command_provider( p_joystick_command_provider )
{
}

command_service::~command_service()
{
}

void command_service::update()
{
    handle_commands( mp_joystick_command_provider->update() );
}

const std::string &command_service::get_name() const
{
    return m_name;
}

void command_service::handle( command::cutter_command* p_command )
{
}

void command_service::handle( command::move_command* p_command )
{
}

void command_service::handle( command::panic_command* p_command )
{
}

void command_service::handle_commands( command::command_set& command_set )
{
    for( auto sp_command : command_set )
    {
        sp_command->accept( this );
    }
}

}

}
