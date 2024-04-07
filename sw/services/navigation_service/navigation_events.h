#pragma once

#include "event/event.h"
#include "utils/geo_pos.h"

namespace services {

namespace navigation_service {

class ev_nav : public ::event::event<ev_nav>
{
public:

    ev_nav( utils::geo_pos position );

    utils::geo_pos get_geo_pos() const;

private:
    utils::geo_pos m_geo_pos;
};

}

}
