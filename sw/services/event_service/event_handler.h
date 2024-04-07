#pragma once

#include "i_event_handler.h"
#include "event/event_manager.h"

namespace services {

namespace event_service {

template <typename T>
class t_impl
{
public:
    virtual void on_event( const T& event ) = 0;
};

template < class... Ts >
class event_handler : public t_impl<Ts>..., public i_event_handler, private ::event::event_manager<Ts>...
{
  public:

    event_handler()
    {
        m_types = { Ts::m_uuid ... };
    }

    using t_impl<Ts>::on_event...;

    std::list<utils::uuid> get_event_types()
    {
        return m_types;
    }

    void dispatch( const ::event::sp_event& spEv )
    {
        ( ( ( ::event::event_manager<Ts>::match( spEv->uuid() ) ) &&
        ( on_event( *::event::event_manager<Ts>::event_cast( spEv.get() ) ), true )) || ... );
    }

private:
    std::list<utils::uuid> m_types;

};

}

}
