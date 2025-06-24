#pragma once

#include "robot/abstract_robot.h"

class simulated_robot : public abstract_robot
{
public:
    simulated_robot( robot_state state, point_2d position, double heading, double battery_level );
    ~simulated_robot();

    void initialize() override;
    void move_to(const point_2d& target) override;
    void stop() override;
    void shutdown() override;

};
