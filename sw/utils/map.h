#pragma once

#include "i_map.h"
#include "polygon.h"

class map : public i_map
{
public:

    map();

    void set_boundary( const polygon& boundary );
    void add_obstacle( const polygon& obstacle );
    void add_soft_obstacle( const polygon &obstacle );

    const polygon& get_boundary() const;
    const std::vector<polygon>& get_obstacles() const;
    const std::vector<polygon>& get_soft_obstacles() const;

private:
    polygon m_boundary;
    std::vector<polygon> m_obstacles;
    std::vector<polygon> m_soft_obstacles;

};
