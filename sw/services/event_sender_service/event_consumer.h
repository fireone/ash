#pragma once

#include "services/event_service/event_handler.h"
#include "services/event_service/event_service.h"
#include "services/event_sender_service/event_sender_events.h"

#include <iostream>

namespace services::event_sender_service
{

/*
 * @brief
 *
 * Dummy class used for development, it consumes ev_a and ev_t1 events
 *
 */

class event_consumer : public services::event_service::event_handler< ev_a, ev_t1 >
{

public:

    /*
     * constructor
     *
     * @param p_event_service pointer to the event service to use.
     * @param p_timer_service pointer to the timer service to use.   
     */
    event_consumer( services::event_service::i_event_service* p_event_service,
                    services::timer_service::i_timer_service* p_timer_service )
    : m_p_event_service( p_event_service )
    , m_p_timer_service( p_timer_service )
    {
        p_event_service->add_event_handler( this );
        p_timer_service->add_timer_event_handler( this );
    }

    ~event_consumer()
    {
        m_p_event_service->remove_event_handler( this );
        m_p_timer_service->remove_timer_event_handler( this );
    }

    void on_event( const ev_a& event )
    {
        std::cout << "event_consumer ev_a - " <<  event.uuid() << std::endl;
    }

    void on_event( const ev_t1& event )
    {
        std::cout << "event_consumer ev_t1 - " << event.uuid() << std::endl;
    }

private:

    services::event_service::i_event_service* m_p_event_service;
    services::timer_service::i_timer_service* m_p_timer_service;
};

}
