#pragma once

#include "builder/sensors/i_sensor_builder.h"
#include "sensors/gnss/ublox_zed_f9r.h"

namespace builder
{

namespace sensors
{

namespace gnss
{

class ublox_zed_f9r_builder : public i_sensor_builder
{
public:
    ublox_zed_f9r_builder();

    ::sensors::i_sensor* build( const parameter_list&        parameters,
                                context::i_context_registry* p_context_registry );

    const std::string& get_sensor_name() const;

private:

    std::string m_sensor_name;
};

}

}

}
