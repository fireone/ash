#pragma once

#include "services/simulator_service/simulator_events.h"
#include "services/route_service/route_events.h"
#include "event/event_handler.h"
#include "services/event_service/i_event_service.h"

#include <QObject>

class EventBridge : public QObject, ::event::event_handler< services::simulator_service::ev_sim, 
                                                            services::route_service::ev_grid_route >
{
    Q_OBJECT

public:
    EventBridge( services::event_service::i_event_service* event_service_ptr );

    private:
    services::event_service::i_event_service* m_event_service_ptr;
 
    void on_event( const services::simulator_service::ev_sim& event ) override;

    void on_event( const services::route_service::ev_grid_route& event ) override;

signals:
    void path_generated( const std::vector<grid_cell>& path );

};
