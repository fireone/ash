#pragma once

#include "event/event.h"

namespace services
{

namespace event_sender_service
{

class ev_a : public event::event<ev_a> {};
class ev_b : public event::event<ev_b> {};
class ev_t1 : public event::event<ev_t1> {};
class ev_t2 : public event::event<ev_t2> {};

}

}