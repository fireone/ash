#include "navigation_service_builder.h"
#include "services/navigation_service/navigation_service.h"

#include <iostream>

namespace builder
{

namespace services
{

namespace navigation_service
{

navigation_service_builder::navigation_service_builder( ::services::event_service::i_event_service* p_event_service )
: m_service_name( "navigation_service" )
, mp_event_service( p_event_service )
{
}

::services::i_service* navigation_service_builder::build( const parameter_list& parameters )
{
    std::cout << "navigation_service_builder" << std::endl;

    return new ::services::navigation_service::navigation_service( mp_event_service );
}

const std::string& navigation_service_builder::get_service_name() const
{
    return m_service_name;
}

}

}

}