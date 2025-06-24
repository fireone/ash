#pragma once

#include "i_robot.h"

class abstract_robot : public i_robot
{
public:

    abstract_robot( robot_state state, point_2d position, double heading, double battery_level );

    virtual const robot_state get_robot_state() const;
    virtual const point_2d& get_position() const;
    virtual const double get_heading() const;
    virtual const double get_battery_level() const;

protected:
    robot_state m_state;
    point_2d m_position;
    double m_heading;
    double m_battery_level;
};