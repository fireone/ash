#pragma once

#include "services/event_service/event_handler.h"
#include "services/event_service/event_service.h"
#include "services/timer_service/i_timer_service.h"
#include "services/event_sender_service/event_sender_events.h"

#include <iostream>

namespace services
{

namespace event_sender_service
{

class timer_event_consumer : public services::event_service::event_handler< ev_t1, ev_t2 >
{

public:

    timer_event_consumer( services::timer_service::i_timer_service* p_timer_service )
    : m_p_timer_service( p_timer_service )
    {
        p_timer_service->add_timer_event_handler( this );

        p_timer_service->schedule_cyclic_event( event::sp_event( new ev_t1 ), 5000 );
        p_timer_service->schedule_cyclic_event( event::sp_event( new ev_t2 ), 2000 );
    }

    ~timer_event_consumer()
    {
        m_p_timer_service->remove_timer_event_handler( this );
    }

    void on_event( const ev_t1& event )
    {
        std::cout << "timer_event_consumer ev_t1 - " << event.uuid() << std::endl;
    }
     
    void on_event( const ev_t2& event )
    {
        std::cout << "timer_event_consumer ev_t2 - " <<  event.uuid() << std::endl;
    }

private:

    services::timer_service::i_timer_service* m_p_timer_service;
};

}

}