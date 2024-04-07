#include "move_command.h"

namespace command
{

move_command::move_command()
{
}

void move_command::accept( i_command_handler* p_handler ) 
{
    p_handler->handle( this );
}

}
