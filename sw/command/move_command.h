#pragma once

#include "i_command.h"

namespace command
{

class move_command : public i_command
{
public:
    move_command();

    void accept( i_command_handler* p_handler );
};

}

