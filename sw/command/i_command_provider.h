#pragma once

#include "i_command.h"

namespace command
{

class i_command_provider
{
public:
    virtual ~i_command_provider(){}

    virtual command_set& update() = 0;
};

}
