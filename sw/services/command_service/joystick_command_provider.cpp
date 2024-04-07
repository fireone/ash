#include "joystick_command_provider.h"

#include "command/panic_command.h"
#include "command/cutter_command.h"

namespace services::command_service
{

joystick_command_provider::joystick_command_provider()
: m_command_set()
{

}

command::command_set& joystick_command_provider::update()
{
    m_command_set.clear();

    m_command_set.push_back( command::sp_commands( new command::panic_command ) );
    m_command_set.push_back( command::sp_commands( new command::cutter_command( 45.0 ) ) );

    return m_command_set;
}

}

// Copy this :)
// https://handmade.network/forums/t/3673-modern_way_to_read_gamepad_input_with_c_on_linux