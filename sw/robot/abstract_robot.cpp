#include "abstract_robot.h"

abstract_robot::abstract_robot( robot_state state, point_2d position, double heading, double battery_level )
    : m_state( state )
    , m_position( position )
    , m_heading( heading )
    , m_battery_level( battery_level )
{}

const robot_state abstract_robot::get_robot_state() const
{
    return m_state;
}

const point_2d& abstract_robot::get_position() const
{
    return m_position;
}

const double abstract_robot::get_heading() const
{
    return m_heading;
}

const double abstract_robot::get_battery_level() const
{
    return m_battery_level;
}