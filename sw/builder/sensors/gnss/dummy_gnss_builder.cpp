#include "dummy_gnss_builder.h"
#include "sensors/gnss/dummy_gnss.h"

#include <iostream>

namespace builder
{

namespace sensors
{

namespace gnss
{

dummy_gnss_builder::dummy_gnss_builder()
: m_sensor_name( ::sensors::gnss::dummy_gnss::name )
{
}

::sensors::i_sensor* dummy_gnss_builder::build( const parameter_list&        parameters,
                                                context::i_context_registry* p_context_registry )
{
    return new ::sensors::gnss::dummy_gnss;
}

const std::string& dummy_gnss_builder::get_sensor_name() const
{
    return m_sensor_name;
}

}

}

}
