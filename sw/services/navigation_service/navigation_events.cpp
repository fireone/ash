#include "navigation_events.h"

namespace services 
{
    
namespace navigation_service
{

EVENT_IMPLEMENT_LOCAL( ev_nav )

ev_nav::ev_nav( utils::geo_pos position )
: m_geo_pos( position )
{
}

utils::geo_pos ev_nav::get_geo_pos() const
{
    return m_geo_pos;
}

}

}
