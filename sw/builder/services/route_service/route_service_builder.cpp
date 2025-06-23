#include "route_service_builder.h"
#include "services/route_service/route_service.h"

#include <iostream>

namespace builder
{

namespace services
{

namespace route_service
{

route_service_builder::route_service_builder( ::services::event_service::i_event_service* p_event_service )
: m_service_name( "route_service" )
, mp_event_service( p_event_service )
{
}

::services::i_service* route_service_builder::build( const parameter_list& parameters )
{
    std::cout << "route_service_builder" << std::endl;

    return new ::services::route_service::route_service( mp_event_service );
}

const std::string& route_service_builder::get_service_name() const
{
    return m_service_name;
}

}

}

}
