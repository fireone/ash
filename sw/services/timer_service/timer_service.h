#pragma once

#include "i_timer_service.h"
#include <vector>
#include <map>

namespace services {

namespace timer_service {

class timer_service : public i_timer_service

{

public:

    timer_service();

    const std::string& get_name() const;
    
    void add_timer_event_handler( ::event::i_event_handler* p_handler );

    void remove_timer_event_handler( ::event::i_event_handler* p_handler );

    void schedule_single_event( const ::event::sp_event& sp_event, unsigned long timer_ms );

    void schedule_cyclic_event( const ::event::sp_event& sp_event, unsigned long timer_ms );

    void update();

private:

    std::string m_name;

    typedef ::std::vector< ::event::i_event_handler* > event_handlers;
    event_handlers m_handlers;

    struct timer_event_plan
    {
        timer_event_plan( const event::sp_event& sp_event, uint64_t& when, unsigned long reschedule )
            : msp_event( sp_event )
            , m_when( when )
            , m_reschedule( reschedule )
        {}

        event::sp_event msp_event;
        uint64_t m_when;
        unsigned long m_reschedule;
    };

    typedef ::std::vector< timer_event_plan > timer_events;
    timer_events m_timer_events;
    timer_events m_added_events;

    void schedule( const event::sp_event& sp_event, unsigned long timer_ms, bool is_cyclic );

    void reschedule( timer_event_plan& timer_event_plan );

    void insert_sorted( const timer_event_plan& timer_event_plan );

};

}

}
