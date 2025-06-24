// filepath: /robot-project/robot-project/src/robot.cpp
#include "robot.h"

robot::robot() 
: abstract_robot( robot_state::IDLE, point_2d(0, 0), 0.0, 100.0 )
{}

robot::~robot() {}

void robot::initialize() {
    // Initialization logic here
}

void robot::move_to(const point_2d& target) {
    // Movement logic here
}

void robot::stop() {
    // Stopping logic here
}

void robot::shutdown() {
    // Shutdown logic here
}

