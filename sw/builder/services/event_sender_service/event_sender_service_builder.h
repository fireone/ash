#pragma once

#include "builder/services/i_service_builder.h"
#include "services/event_service/i_event_service.h"
#include "services/timer_service/i_timer_service.h"


namespace builder
{

namespace services
{

namespace event_sender_service
{

class event_sender_service_builder : public i_service_builder
{
public:
    event_sender_service_builder( ::services::event_service::i_event_service* p_event_service,
                                  ::services::timer_service::i_timer_service* p_timer_service );

    ::services::i_service* build( const parameter_list& parameters );
    
    const std::string& get_service_name() const;

private:

    std::string m_service_name;
    
    ::services::event_service::i_event_service* mp_event_service;
    ::services::timer_service::i_timer_service* mp_timer_service;

};

}

}

}
