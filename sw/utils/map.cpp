#include "map.h"

map::map()
: m_boundary()
, m_obstacles()
, m_soft_obstacles()
{}

void map::set_boundary( const polygon& boundary )
{
    m_boundary = boundary;
}

void map::add_obstacle( const polygon& obstacle )
{
    m_obstacles.push_back( obstacle );
}

void map::add_soft_obstacle(const polygon &obstacle)
{
    m_soft_obstacles.push_back( obstacle );
}

const polygon& map::get_boundary() const
{
    return m_boundary;
}

const std::vector<polygon>& map::get_obstacles() const
{
    return m_obstacles;
}

const std::vector<polygon> &map::get_soft_obstacles() const
{
    return m_soft_obstacles;
}
