#pragma once

#include "event/event.h"

namespace services {

namespace simulator_service {

class ev_sim : public ::event::event<ev_sim>
{
public:

    ev_sim();

private:
};

}

}
