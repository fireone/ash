#pragma once

#include "services/i_service.h"
#include "services/event_service/i_event_service.h"

#include "robot/i_robot.h"

#include "gui/MainWindow.h"

#include "utils/i_map.h"

#include <memory>

namespace services
{

namespace simulator_service
{

class simulator_service : public i_service
{
public:
    simulator_service( event_service::i_event_service* p_event_service );

    ~simulator_service();

    void update();

    const std::string& get_name() const;

private:
    std::string m_name;
    
    event_service::i_event_service* mp_event_service;

    std::unique_ptr<MainWindow> m_main_window_ptr;

    std::unique_ptr<i_robot> m_robot_ptr;

    std::unique_ptr<i_map> m_map_ptr;
};

}

}
