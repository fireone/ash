#pragma once

#include "event/event.h"
#include "utils/geo_pos.h"

namespace services {

namespace route_service {

class ev_route : public ::event::event<ev_route>
{
public:

    ev_route( );

    utils::geo_pos get_geo_pos() const;

private:
    utils::geo_pos m_geo_pos;
};

}

}
