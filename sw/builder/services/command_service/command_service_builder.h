#pragma once

#include "builder/services/i_service_builder.h"
#include "services/event_service/i_event_service.h"

namespace builder
{

namespace services
{

namespace command_service
{

class command_service_builder : public i_service_builder
{
public:
    command_service_builder( ::services::event_service::i_event_service* p_event_service );

    ::services::i_service* build( const parameter_list& parameters );
    
    const std::string& get_service_name() const;

private:

    std::string m_service_name;
    
    ::services::event_service::i_event_service* mp_event_service;

};

}

}

}
