#pragma once

#include <memory>
#include "utils/uuid.h"

namespace event {

class i_event
{
public:
    virtual ~i_event(){}

    virtual utils::uuid uuid() const = 0;
};

typedef ::std::shared_ptr<i_event> sp_event;

}


