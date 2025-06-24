#include "abstract_robot.h"

class robot : public abstract_robot
{       

public:
    robot();
    ~robot();

    void initialize() override;
    void move_to(const point_2d& target) override;
    void stop() override;
    void shutdown() override;

};

