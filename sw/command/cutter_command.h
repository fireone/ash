#pragma once

#include "i_command.h"

namespace command
{

class cutter_command : public i_command
{
public:
    cutter_command( double rpm );

    double get_rpm();

    void accept( i_command_handler* p_handler );

private:

    double m_rpm;
};

}

