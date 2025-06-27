#include "route_service.h"
#include "route_events.h"

#include <iostream>

namespace services
{

namespace route_service
{

route_service::route_service( event_service::i_event_service* p_event_service )
: m_name( "route_service" )
, mp_event_service( p_event_service )
, m_do_work( false )
{
    mp_event_service->add_event_handler( this );
}

route_service::~route_service()
{
}

void route_service::update()
{
    if( m_do_work )
    {
        std::vector<grid_cell> path = {
            {0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}, {3, 2},
            {3, 3}, {4, 3}, {4, 4}, {5, 4}, {5, 5}
        };
        
        event::sp_event sp_ev( new ev_grid_route( path ) );

        mp_event_service->dispatch( sp_ev );

        m_do_work = false;
    }
}

const std::string &route_service::get_name() const
{
    return m_name;
}

void route_service::on_event( const ev_request_grid_route& event )
{
    m_do_work = true;
}

}

}
