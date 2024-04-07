#include "event_sender_service_builder.h"
#include "services/event_sender_service/event_sender_service.h"

#include <iostream>

namespace builder
{

namespace services
{

namespace event_sender_service
{

event_sender_service_builder::event_sender_service_builder( ::services::event_service::i_event_service* p_event_service,
                                                            ::services::timer_service::i_timer_service* p_timer_service )
: m_service_name( "event_sender_service" )
, mp_event_service( p_event_service )
, mp_timer_service( p_timer_service )
{
}

::services::i_service* event_sender_service_builder::build( const parameter_list& parameters )
{
    std::cout << "event_sender_service_builder" << std::endl;

    return new ::services::event_sender_service::event_sender_service( mp_event_service, mp_timer_service );
}

const std::string& event_sender_service_builder::get_service_name() const
{
    return m_service_name;
}

}

}

}