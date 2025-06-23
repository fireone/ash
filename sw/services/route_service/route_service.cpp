#include "route_service.h"
#include "route_events.h"

#include <iostream>

namespace services
{

namespace route_service
{

route_service::route_service( event_service::i_event_service* p_event_service )
: m_name( "route_service" )
, mp_event_service( p_event_service )
{
}

route_service::~route_service()
{
}

void route_service::update()
{

}

const std::string &route_service::get_name() const
{
    return m_name;
}

}

}
