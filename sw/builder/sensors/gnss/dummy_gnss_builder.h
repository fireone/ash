#pragma once

#include "builder/sensors/i_sensor_builder.h"

namespace builder
{

namespace sensors
{

namespace gnss
{

class dummy_gnss_builder : public i_sensor_builder
{
public:
    dummy_gnss_builder();

    ::sensors::i_sensor* build( const parameter_list&        parameters,
                                context::i_context_registry* p_context_registry );
    
    const std::string& get_sensor_name() const;

private:

    std::string m_sensor_name;

};

}

}

}
