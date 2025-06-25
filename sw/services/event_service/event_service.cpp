#include "event_service.h"
#include <algorithm>
#include <mutex>

namespace services {
namespace event_service {

std::mutex added_events_mutex;
std::mutex event_handler_mutex;

event_service::event_service()
: m_name( "event_service" )
, m_handlers()
, m_events()
, m_events_to_dispatch()
{
}

const std::string &event_service::get_name() const
{
    return m_name;
}

void event_service::add_event_handler( ::event::i_event_handler* p_handler )
{
    std::lock_guard<std::mutex> guard( event_handler_mutex );
    
    m_handlers.push_back( p_handler );
}

void event_service::remove_event_handler( ::event::i_event_handler* p_handler )
{
    std::lock_guard<std::mutex> guard( event_handler_mutex );
    
    auto it = std::find( m_handlers.begin(), m_handlers.end(), p_handler );

    if( it != m_handlers.end() )
    {
        m_handlers.erase( it );
    }
}

void event_service::dispatch( const ::event::sp_event& sp_ev )
{
    std::lock_guard<std::mutex> guard( added_events_mutex );

    m_events_to_dispatch.push( sp_ev );
}

void event_service::update()
{
    added_events_mutex.lock();

    m_events.swap( m_events_to_dispatch );

    added_events_mutex.unlock();

    ::event::sp_event sp_event;

    while( m_events.size() > 0 )
    {
        sp_event = m_events.front();

        std::lock_guard<std::mutex> guard( event_handler_mutex );
        
        for( auto p_handler : m_handlers )
        {
            p_handler->dispatch( sp_event );
        }

        m_events.pop();
    }
}

}

}
