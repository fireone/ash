#include "simulator_service.h"
#include "simulator_events.h"

#include "robot/simulated_robot.h"

#include "utils/map.h"

#include "services/route_service/route_events.h"

#include <iostream>


//TODO: For testing, change to recieve map from event
void add_map_objects( i_map* map_ptr )
{
    polygon boundary;

    boundary.addPoint( 0.0, 0.0 );
    boundary.addPoint( 500.0, 0.0 );
    boundary.addPoint( 500.0, 500.0 );
    boundary.addPoint( 0.0, 500.0 );

    boundary.close();

    boundary.setContainmentMode( polygon::ContainmentMode::Strict );

    polygon obs1;

    obs1.addPoint( 75.0, 75.0 );
    obs1.addPoint( 100.0, 75.0 );
    obs1.addPoint( 100.0, 100.0 );
    obs1.addPoint( 75.0, 100.0 );

    obs1.close();
    obs1.setContainmentMode( polygon::ContainmentMode::Strict );

    polygon obs2;

    obs2.addPoint(   0.0, 200.0 );
    obs2.addPoint(   0.0, 250.0 );
    obs2.addPoint( 500.0, 250.0 );
    obs2.addPoint( 500.0, 200.0 );

    obs2.close();
    obs2.setContainmentMode( polygon::ContainmentMode::Strict );

    polygon obs3;

    obs3.addPoint( 250.0, 200.0 );
    obs3.addPoint( 200.0, 250.0 );
    obs3.addPoint( 300.0, 350.0 );
    obs3.addPoint( 350.0, 220.0 );

    obs3.close();
    obs3.setContainmentMode( polygon::ContainmentMode::Strict );

    polygon obs4;

    obs4.addPoint( 250.0-80, 200.0+50 );
    obs4.addPoint( 200.0-80, 250.0+50 );
    obs4.addPoint( 300.0-80, 350.0+50 );
    obs4.addPoint( 350.0-80, 220.0+50 );

    obs4.close();
    obs4.setContainmentMode( polygon::ContainmentMode::Strict );

    polygon obs5;

    obs5.addPoint( 28, 350 );
    obs5.addPoint( 28, 450 );
    obs5.addPoint( 80, 450 );
    obs5.addPoint( 80, 350 );

    obs5.close();
    obs5.setContainmentMode( polygon::ContainmentMode::Strict );

    map_ptr->set_boundary( boundary );
    map_ptr->add_obstacle( obs1 );
    map_ptr->add_obstacle( obs3 );
    map_ptr->add_obstacle( obs4 );
    map_ptr->add_soft_obstacle( obs2 );
    map_ptr->add_soft_obstacle( obs5 );
}

namespace services
{

namespace simulator_service
{

simulator_service::simulator_service( event_service::i_event_service* p_event_service )
: m_name( "simulator_service" )
, mp_event_service( p_event_service )
, m_main_window_ptr()
, m_robot_ptr()
, m_map_ptr()
{
    m_robot_ptr = std::make_unique<simulated_robot>(robot_state::IDLE, point_2d(0.0, 0.0), 180.0, 100.0 );

    m_map_ptr = std::make_unique<map>();

    add_map_objects( m_map_ptr.get() );

    m_main_window_ptr = std::make_unique<MainWindow>( m_map_ptr.get(), m_robot_ptr.get(), mp_event_service );
    
    m_main_window_ptr->show();

    mp_event_service->add_event_handler( this );

    mp_event_service->dispatch( event::sp_event( new ::services::route_service::ev_request_grid_route() ) );
}

simulator_service::~simulator_service()
{
}

void simulator_service::update()
{
}

const std::string& simulator_service::get_name() const
{
    return m_name;
}

void simulator_service::on_event( const ::services::route_service::ev_grid_route& event )
{

}

}

}
