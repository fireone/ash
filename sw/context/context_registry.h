#pragma once

#include "i_context_registry.h"

namespace context
{

class context_registry : public i_context_registry
{
public:

    context_registry();

    ~context_registry();

    context_registry( const context_registry& ) = delete;
    context_registry& operator=( const context_registry& ) = delete;
    context_registry( context_registry && obj ) = delete;
    context_registry& operator=( context_registry && obj ) = delete;

    i_context* register_context( std::string context_name );

    const context_map& get_context_map();

    void start();

    void stop();

private:

    context_map m_context_map;

};

}
