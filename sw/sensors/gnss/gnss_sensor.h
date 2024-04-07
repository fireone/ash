#pragma once

#include "sensors/i_sensor.h"

namespace sensors
{

namespace gnss
{

class gnss_sensor : public i_sensor
{
public:
    virtual double get_lng() const = 0;

    virtual double get_lat() const = 0;
};

}

}
