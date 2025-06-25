#pragma once

#include "i_event_handler.h"
#include "event_manager.h"

namespace event {

template <typename T>
class t_impl
{
public:
    virtual void on_event( const T& event ) = 0;
};

template < class... Ts >
class event_handler : public t_impl<Ts>..., public i_event_handler, private event_manager<Ts>...
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

    void dispatch( const sp_event& spEv )
    {
        ( ( ( event_manager<Ts>::match( spEv->uuid() ) ) &&
        ( on_event( *event_manager<Ts>::event_cast( spEv.get() ) ), true )) || ... );
    }

private:
    std::list<utils::uuid> m_types;

};

}

