#pragma once

#include "i_command.h"

namespace command
{

class panic_command : public i_command
{
public:
    panic_command();

    void accept( i_command_handler* p_handler );
};

}

