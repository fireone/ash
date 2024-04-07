#pragma once

#include "gnss_sensor.h"

namespace sensors
{

namespace gnss
{

class dummy_gnss : public gnss_sensor
{
public:
    dummy_gnss()
    {
    }
    
    const std::string& get_name() const
    {
        return name;
    }
    
    double get_lng() const
    {
        return 60.0;
    }

    double get_lat() const
    {
        return 15.0;
    }

    inline static std::string name = "dummy_gnss";
};

}

}
