#pragma once

#include "i_event.h"

#include <iostream>

namespace event {

template<class T>
class event_manager
{

public:
    static T* event_cast( i_event* pEvent )
    {
        return static_cast<T*>( pEvent );
    }

    static bool match( utils::uuid uuid )
    {
        return uuid == T::m_uuid;
    }
};

}