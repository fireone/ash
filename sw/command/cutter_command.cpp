#include "cutter_command.h"

namespace command
{

cutter_command::cutter_command( double rpm )
: m_rpm( rpm )
{

}

double cutter_command::get_rpm()
{
   return m_rpm;
}

void cutter_command::accept( i_command_handler* p_handler )
{
    p_handler->handle( this );
}

}
