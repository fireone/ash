#pragma once

#include "utils/i_map.h"

namespace services {

namespace simulator_service {

class i_environment
{
public:
    virtual ~i_environment(){}

    virtual const i_map* get_map() const = 0;
};

}

}
