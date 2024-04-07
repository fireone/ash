#pragma once

#include <string>
#include <list>

#include "context/i_updatable.h"

namespace services
{

class i_service : public context::i_updatable
{
public:
    virtual ~i_service(){}

    virtual const std::string& get_name() const = 0;
};

}
