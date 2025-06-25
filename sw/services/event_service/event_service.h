#pragma once

#include "i_event_service.h"
#include <queue>
#include <vector>

namespace services {

namespace event_service {

class event_service : public i_event_service
{

public:

    event_service();

    const std::string& get_name() const;

    void add_event_handler( ::event::i_event_handler* p_handler );

    void remove_event_handler( ::event::i_event_handler* p_handler );

    void dispatch( const ::event::sp_event &sp_ev );

    void update();

private:

    std::string m_name;

    typedef ::std::vector< ::event::i_event_handler* > event_handlers;
    event_handlers m_handlers;

    typedef ::std::queue< ::event::sp_event > events;
    events m_events;
    events m_events_to_dispatch;

};

}

}
