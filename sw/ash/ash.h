#pragma once

#include "context/i_context_registry.h"
#include "sensors/i_sensor.h"

namespace ash {

class ash
{
public:
    ash( context::i_context_registry* p_context_registry, sensors::sensors sensors );

    ~ash();

    void start();

    void stop();

private:
    context::i_context_registry* mp_context_registry;

    sensors::sensors m_sensors;

};

}
