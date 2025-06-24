#pragma once

#include "polygon.h"

#include <vector>

class i_map
{
public:
    virtual ~i_map(){}

    virtual void set_boundary( const polygon& boundary ) = 0;
    virtual void add_obstacle( const polygon& obstacle ) = 0;
    virtual void add_soft_obstacle( const polygon& obstacle ) = 0;

    virtual const polygon& get_boundary() const = 0;
    virtual const std::vector<polygon>& get_obstacles() const = 0;
    virtual const std::vector<polygon>& get_soft_obstacles() const = 0;
};
