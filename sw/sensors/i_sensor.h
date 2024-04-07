#pragma once

#include <string>
#include <list>

namespace sensors
{

class i_sensor
{
public:
    virtual ~i_sensor(){}
    
    virtual const std::string& get_name() const = 0;
};

typedef std::list<i_sensor*> sensors;

}
