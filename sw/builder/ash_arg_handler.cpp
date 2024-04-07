#include "ash_arg_handler.h"

namespace builder
{

arg_map ash_arg_handler::argument_map = { { argument::CONFIG_FILE, "ash_config.xml" },
                                          { argument::DEBUG, "false" } };

void ash_arg_handler::parse_arguments( int argc, char* argv[] )
{
    const std::vector<std::string_view> args( argv + 1, argv + argc );

    for( auto it = begin( args ); it != end( args ); ++it ) 
    {
        if( *it == "-c" )
        {
            ++it;
            argument_map[ argument::CONFIG_FILE ] = *it;
        }
        else if( *it == "-d" )
        {
            argument_map[ argument::DEBUG ] = "true";
        }
    }
}

std::string ash_arg_handler::config_file()
{
    return argument_map[ argument::CONFIG_FILE ];
}

}
