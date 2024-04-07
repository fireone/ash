#include "panic_command.h"

namespace command
{

panic_command::panic_command()
{
}

void panic_command::accept( i_command_handler* p_handler ) 
{
    p_handler->handle( this );
}

}
