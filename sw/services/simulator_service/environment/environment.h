#pragma once

#include "i_environment.h"

namespace services {

namespace simulator_service {

class environment : public i_environment
{
public:
    environment( i_map* map_ptr );

    const i_map *get_map() const;

private:
    i_map* m_map_ptr;
};

}

}
