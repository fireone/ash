#include "ublox_zed_f9r_builder.h"
#include "context/context.h"

#include <iostream>

namespace builder
{

namespace sensors
{

namespace gnss
{

ublox_zed_f9r_builder::ublox_zed_f9r_builder()
: m_sensor_name( ::sensors::gnss::ublox_zed_f9r::name )
{
}

::sensors::i_sensor* ublox_zed_f9r_builder::build( const parameter_list&        parameters,
                                                   context::i_context_registry* p_context_registry )
{
    return new ::sensors::gnss::ublox_zed_f9r( parameters.at( "device" ),
                                               p_context_registry->register_context( parameters.at( "context" ) ) );
}

const std::string& ublox_zed_f9r_builder::get_sensor_name() const
{
    return m_sensor_name;
}

}

}

}