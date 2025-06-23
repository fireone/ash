#pragma once

#include "services/i_service.h"
#include "services/event_service/i_event_service.h"

namespace services
{

namespace route_service
{

class route_service : public i_service
{
public:
    route_service( event_service::i_event_service* p_event_service );

    ~route_service();

    void update();

    const std::string& get_name() const;

private:
    std::string m_name;
    
    event_service::i_event_service* mp_event_service;
};

}

}
