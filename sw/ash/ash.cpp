#include "ash.h"

namespace ash {

ash::ash( context::i_context_registry* p_context_registry,
          sensors::sensors             sensors )
: mp_context_registry( p_context_registry )
, m_sensors{ std::move( sensors) }
{
}

ash::~ash()
{
    for( auto sensor : m_sensors )
    {
        delete sensor;
    } 

    delete mp_context_registry;
}

void ash::start()
{
    mp_context_registry->start();
}

void ash::stop()
{
    mp_context_registry->stop();
}

}
