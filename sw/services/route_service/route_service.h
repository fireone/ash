#pragma once

#include "route_events.h"

#include "services/i_service.h"
#include "services/event_service/i_event_service.h"
#include "services/event_service/event_handler.h"

namespace services
{

namespace route_service
{

class route_service : public i_service, services::event_service::event_handler< ev_request_grid_route >
{
public:
    route_service( event_service::i_event_service* p_event_service );

    ~route_service();

    void update();

    const std::string& get_name() const;

    void on_event( const ev_request_grid_route& event );

private:
    std::string m_name;
    
    bool m_do_work;

    event_service::i_event_service* mp_event_service;
};

}

}
