#include "simulator_service_builder.h"
#include "services/simulator_service/simulator_service.h"

#include <iostream>

namespace builder
{

namespace services
{

namespace simulator_service
{

simulator_service_builder::simulator_service_builder( ::services::event_service::i_event_service* p_event_service )
: m_service_name( "simulator_service" )
, mp_event_service( p_event_service )
{
}

::services::i_service* simulator_service_builder::build( const parameter_list& parameters )
{
    std::cout << "simulator_service_builder" << std::endl;

    return new ::services::simulator_service::simulator_service( mp_event_service );
}

const std::string& simulator_service_builder::get_service_name() const
{
    return m_service_name;
}

}

}

}
