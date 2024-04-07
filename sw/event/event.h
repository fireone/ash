#pragma once

#include "i_event.h"

namespace event {

template<class T>
class event : public i_event
{
public:
   
   const utils::uuid uuid() const
   {
      return m_uuid;
   }

   static const utils::uuid m_uuid;
};

}

#define EVENT_IMPLEMENT_GLOBAL( _ev_type_, _uuid_ ) template<> \
const utils::uuid event::event< _ev_type_ >::m_uuid( _uuid_ );

#define EVENT_IMPLEMENT_LOCAL( _ev_type_ ) template<> \
const utils::uuid event::event< _ev_type_ >::m_uuid{};

