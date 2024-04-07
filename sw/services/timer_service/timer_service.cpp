#include "timer_service.h"
#include <chrono>
#include <algorithm>
#include <mutex>

namespace services {

namespace timer_service {

std::mutex added_events_mutex;

timer_service::timer_service()
: m_name( "timer_service" )
, m_handlers()
, m_timer_events()
, m_added_events()
{
}

const std::string &timer_service::get_name() const
{
    return m_name;
}

void timer_service::add_timer_event_handler( services::event_service::i_event_handler* pHandler )
{
    m_handlers.push_back( pHandler );
}

void timer_service::remove_timer_event_handler( services::event_service::i_event_handler* pHandler )
{
    auto it = std::find( m_handlers.begin(), m_handlers.end(), pHandler );

    if( it != m_handlers.end() )
    {
        m_handlers.erase( it );
    }
}

void timer_service::schedule_single_event( const ::event::sp_event& spEvent, unsigned long timer_ms )
{
    schedule( spEvent, timer_ms, false );
}

void timer_service::schedule_cyclic_event( const ::event::sp_event& spEvent, unsigned long timer_ms )
{
    schedule( spEvent, timer_ms, true );
}

void timer_service::schedule( const ::event::sp_event& spEvent, unsigned long timer_ms, bool isCyclic )
{
    using namespace std::chrono;

    uint64_t when( duration_cast<milliseconds>( system_clock::now().time_since_epoch() ).count() + timer_ms );

    timer_event_plan timerEventPlan( spEvent, when, isCyclic ? timer_ms : 0 );

    std::lock_guard<std::mutex> guard( added_events_mutex );

    m_added_events.push_back( timerEventPlan );
}

void timer_service::reschedule( timer_event_plan& timerEventPlan )
{
    timerEventPlan.m_when += timerEventPlan.m_reschedule;

    m_added_events.push_back( timerEventPlan );
}

void timer_service::update()
{
    ::event::sp_event spEvent;

    added_events_mutex.lock();

    for( timer_event_plan& timerEventPlan : m_added_events )
    {
        insert_sorted( timerEventPlan );
    }
    
    m_added_events.clear();

    added_events_mutex.unlock();

    if( m_timer_events.size() == 0 )
    {
        return;
    }

    using namespace std::chrono;

    uint64_t timeNow( duration_cast<milliseconds>( system_clock::now().time_since_epoch() ).count() );

    for( auto it = m_timer_events.begin(); it < m_timer_events.end(); it++ )
    {
        if( it->m_when < timeNow )
        {
            for( auto p_handler : m_handlers )
            {
                p_handler->dispatch( it->msp_event );
            }

            if( it->m_reschedule > 0 )
            {
                reschedule( *it );    
            }
            m_timer_events.erase( it );
        }
        else
        {
            break;
        }
    }
}

void timer_service::insert_sorted( const timer_service::timer_event_plan& timerEventPlan )
{
    for( auto it = m_timer_events.begin(); it < m_timer_events.end(); ++it )
    {
        if( timerEventPlan.m_when < it->m_when )
        {
            m_timer_events.insert( it, timerEventPlan );

            return;
        }
    }

    m_timer_events.push_back( timerEventPlan );
}

}

}