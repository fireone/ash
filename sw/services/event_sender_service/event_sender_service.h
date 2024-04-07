#pragma once

#include "services/i_service.h"
#include "services/event_service/i_event_service.h"
#include "services/timer_service/i_timer_service.h"

#include "event_consumer.h"
#include "timer_event_consumer.h"

namespace services
{

namespace event_sender_service
{

class event_sender_service : public i_service
{
public:
    event_sender_service( event_service::i_event_service* p_event_service,
                          timer_service::i_timer_service* p_timer_service );

    ~event_sender_service();

    void update();

    const std::string& get_name() const;

private:
    std::string m_name;
    
    event_service::i_event_service* mp_event_service;

    event_consumer* mp_event_consumer;

    timer_event_consumer* mp_timer_event_consumer;
};

}

}