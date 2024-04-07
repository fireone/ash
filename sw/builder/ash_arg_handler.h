#pragma once

#include <vector>
#include <map>
#include <string>

namespace builder
{

enum class argument
{
    DEBUG,
    CONFIG_FILE
};

typedef std::map<argument, std::string> arg_map;

class ash_arg_handler
{
public:
    static void parse_arguments( int argc, char* argv[] );

    static std::string config_file();

private:

    static arg_map argument_map;
};

}
