#pragma once

#include "services/i_service.h"
#include "i_event_handler.h"

namespace services {

namespace event_service {

class i_event_service : public i_service
{

public:

    virtual ~i_event_service(){}

    virtual void add_event_handler( i_event_handler* ) = 0;

    virtual void remove_event_handler( i_event_handler* ) = 0;

    virtual void dispatch( const ::event::sp_event& ) = 0;

 };

}

}
