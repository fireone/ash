#include "event_sender_service.h"
#include "event_sender_events.h"

#include <iostream>

namespace services
{

namespace event_sender_service
{

event_sender_service::event_sender_service( event_service::i_event_service* p_event_service,
                                            timer_service::i_timer_service* p_timer_service )
: m_name( "event_sender_service" )
, mp_event_service( p_event_service )
, mp_event_consumer( new event_consumer( p_event_service, p_timer_service ) )
, mp_timer_event_consumer( new timer_event_consumer( p_timer_service ) )
{
}

event_sender_service::~event_sender_service()
{
    delete mp_event_consumer;
    delete mp_timer_event_consumer;
}

void event_sender_service::update()
{
    mp_event_service->dispatch( event::sp_event( new ev_a ) );
    mp_event_service->dispatch( event::sp_event( new ev_b ) );
}

const std::string &event_sender_service::get_name() const
{
    return m_name;
}

}

}
