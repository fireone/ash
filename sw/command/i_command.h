#pragma once

#include "i_command_handler.h"

#include <memory>
#include <vector>

namespace command
{

class i_command
{
public:
    virtual ~i_command(){}

    virtual void accept( i_command_handler* p_handler ) = 0;
};

typedef std::shared_ptr<i_command> sp_commands;
typedef std::vector<sp_commands> command_set;

}
