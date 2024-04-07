#include "context_registry.h"
#include "context.h"

#include <iostream>

namespace context
{

context_registry::context_registry()
: m_context_map()
{
}

context_registry::~context_registry()
{
    // reverse order to save event and timer service for last
    for( auto it( m_context_map.crbegin() ); it != m_context_map.crend(); ++it )
    {
        delete it->second;
    }
}

i_context* context_registry::register_context( std::string context_name )
{
    if( m_context_map.contains( context_name ) )
    {
        return m_context_map[ context_name ];
    }
    
    i_context* p_context = new context();
    
    m_context_map[ context_name ] = p_context;

    return p_context;
}

const context_map& context_registry::get_context_map()
{
    return m_context_map;
}

void context_registry::start()
{
    for( auto& context : m_context_map )
    {
        context.second->start();

        std::cout << "Starting thread: " << context.first << std::endl;
    }
}

void context_registry::stop()
{
    for( auto it( m_context_map.crbegin() ); it != m_context_map.crend(); ++it )
    {
        it->second->stop();

        std::cout << "Stoping thread: " << it->first << std::endl;
    }
}

}
