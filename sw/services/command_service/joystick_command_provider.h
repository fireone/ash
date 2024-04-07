#pragma once

#include "command/i_command_provider.h"

namespace services::command_service
{

/*
 * @brief
 * 
 * Class that handles a gamepad and creates the associated
 * commands from it.
 */

class joystick_command_provider : public command::i_command_provider
{
public:

    /*
     * constructor
     */
    joystick_command_provider();

    command::command_set& update();

private:
    command::command_set m_command_set;

};

}