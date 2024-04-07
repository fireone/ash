#include "navigation_service.h"
#include "navigation_events.h"

#include <iostream>

namespace services
{

namespace navigation_service
{

navigation_service::navigation_service( event_service::i_event_service* p_event_service )
: m_name( "navigation_service" )
, mp_event_service( p_event_service )
{
}

navigation_service::~navigation_service()
{
}

void navigation_service::update()
{

}

const std::string &navigation_service::get_name() const
{
    return m_name;
}

}

}
