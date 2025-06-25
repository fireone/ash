#pragma once

#include <list>

#include "event/event.h"

namespace event {

class i_event_handler
{
public:
    virtual ~i_event_handler(){}

    virtual std::list<utils::uuid> get_event_types() = 0;

    virtual void dispatch( const ::event::sp_event& ) = 0;

};

}
