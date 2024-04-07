#pragma once

#include "services/i_service.h"
#include "services/event_service/i_event_service.h"

#include "command/i_command.h"
#include "command/i_command_handler.h"
#include "command/i_command_provider.h"

namespace services
{

namespace command_service
{

/*
 * @brief
 *
 * Service that will manage the control of the robot lawn mower.
 * 
 * @todo
 *  - Add more command sources
 *  - Implement handlers 
 *  - probably more...
 */


class command_service : public i_service, private command::i_command_handler
{
public:

    /*
     * constructor
     * 
     * @param p_event_service     pointer to an event service
     * @param p_joystick_command  pointer to a joystick command provider, ownership assumed. 
     * 
     */
    command_service( event_service::i_event_service* p_event_service,
                     command::i_command_provider*    p_joystick_command_provider );

    ~command_service();

    void update();

    const std::string& get_name() const;

private:

    void handle( command::cutter_command* p_command );

    void handle( command::move_command* p_command );

    void handle( command::panic_command* p_command );

    void handle_commands( command::command_set& command_set );

    std::string m_name;
    
    event_service::i_event_service* mp_event_service;

    command::i_command_provider* mp_joystick_command_provider;
};

}

}
