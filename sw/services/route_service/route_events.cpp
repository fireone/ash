#include "route_events.h"

namespace services 
{
    
namespace route_service
{

EVENT_IMPLEMENT_LOCAL( ev_route )
EVENT_IMPLEMENT_LOCAL( ev_request_grid_route )
EVENT_IMPLEMENT_LOCAL( ev_grid_route )

ev_route::ev_route()
: m_geo_pos()
{
}

utils::geo_pos ev_route::get_geo_pos() const
{
    return m_geo_pos;
}


ev_request_grid_route::ev_request_grid_route()
{
}

ev_grid_route::ev_grid_route()
{
}

}

}
