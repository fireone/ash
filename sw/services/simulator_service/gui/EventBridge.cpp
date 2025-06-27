#include "EventBridge.h"

EventBridge::EventBridge( services::event_service::i_event_service* event_service_ptr )
    : m_event_service_ptr( event_service_ptr )
{
    m_event_service_ptr->add_event_handler( this );
}

void EventBridge::on_event( const services::simulator_service::ev_sim& event )
{
    // Handle the event here
    // For example, you might want to update the GUI or trigger some action in the simulator
    // qDebug() << "Event received in EventBridge";
}

void EventBridge::on_event( const services::route_service::ev_grid_route& event )
{
    emit path_generated( event.get_path() );
}
