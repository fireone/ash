#include "simulated_robot.h"

simulated_robot::simulated_robot( robot_state state, point_2d position, double heading, double battery_level )
    : abstract_robot( state, position, heading, battery_level )
{
}

simulated_robot::~simulated_robot() = default;

void simulated_robot::initialize()
{
    m_state = IDLE;
    m_position = point_2d(0.0, 0.0);
    m_heading = 0.0;
    m_battery_level = 100.0;
}

void simulated_robot::move_to( const point_2d& target )
{
    m_position = target;
    m_state = MOVING;
    // Heading and battery logic can be expanded as needed
}

void simulated_robot::stop()
{
    m_state = STOPPED;
}

void simulated_robot::shutdown()
{
    m_state = SHUTDOWN;
    m_battery_level = 0.0;
}



