#pragma once

#include "services/i_service.h"
#include "services/event_service/i_event_service.h"
#include "services/event_service/event_handler.h"
#include "services/route_service/route_events.h"


#include "robot/i_robot.h"

#include "gui/MainWindow.h"

#include "utils/i_map.h"

#include <memory>

namespace services
{

namespace simulator_service
{

class simulator_service : public i_service, services::event_service::event_handler< ::services::route_service::ev_grid_route >
{
public:
    simulator_service( event_service::i_event_service* p_event_service );

    ~simulator_service();

    void update();

    const std::string& get_name() const;

    void on_event( const ::services::route_service::ev_grid_route& event );

private:
    std::string m_name;
    
    event_service::i_event_service* mp_event_service;

    std::unique_ptr<MainWindow> m_main_window_ptr;

    std::unique_ptr<i_robot> m_robot_ptr;

    std::unique_ptr<i_map> m_map_ptr;
};

}

}
