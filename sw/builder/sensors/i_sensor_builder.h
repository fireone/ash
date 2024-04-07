#pragma once

#include "sensors/i_sensor.h"
#include "context/context_registry.h"

#include <map>
#include <string>

namespace builder
{

namespace sensors
{

typedef std::map<std::string, std::string> parameter_list;

class i_sensor_builder
{
public:
    virtual ~i_sensor_builder(){}

    virtual ::sensors::i_sensor* build( const parameter_list&        parameters,
                                        context::i_context_registry* context_registry ) = 0;

    virtual const std::string& get_sensor_name() const = 0;
};

}

}
