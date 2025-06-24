#pragma once

#include "utils/point_2d.h"

enum robot_state {
    IDLE,
    MOVING,
    STOPPED,
    SHUTDOWN
};

class i_robot {
public:
    virtual ~i_robot() = default;

    virtual void initialize() = 0;
    virtual void move_to(const point_2d& target) = 0;
    virtual void stop() = 0;
    virtual void shutdown() = 0;

    virtual const robot_state get_robot_state() const = 0;
    virtual const point_2d& get_position() const = 0;
    virtual const double get_heading() const = 0;
    virtual const double get_battery_level() const = 0;
};