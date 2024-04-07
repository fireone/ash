#pragma once

#include <map>
#include <string>
#include "i_context.h"

namespace context
{

typedef std::map<std::string, i_context*> context_map;

class i_context_registry
{
public:

    virtual ~i_context_registry(){}

    virtual i_context* register_context( std::string context_name ) = 0;

    virtual const context_map& get_context_map() = 0;

    virtual void start() = 0;

    virtual void stop() = 0;
};

}