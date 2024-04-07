#pragma once

#include "services/i_service.h"
#include "services/event_service/i_event_handler.h"
#include "event/i_event.h"

namespace services {

namespace timer_service {

class i_timer_service : public i_service
{

public:

    virtual ~i_timer_service(){}

    virtual void add_timer_event_handler( services::event_service::i_event_handler* ) = 0;

    virtual void remove_timer_event_handler( services::event_service::i_event_handler* ) = 0;

    virtual void schedule_single_event( const ::event::sp_event&, unsigned long timer_ms ) = 0;

    virtual void schedule_cyclic_event( const ::event::sp_event&, unsigned long timer_ms ) = 0;

 };

}

}
