#pragma once

namespace command
{

class cutter_command;
class panic_command;
class move_command;

class i_command_handler
{
public:
    virtual ~i_command_handler(){}

    virtual void handle( cutter_command* p_command ) = 0;

    virtual void handle( move_command* p_command ) = 0;

    virtual void handle( panic_command* p_command ) = 0;
};

}
