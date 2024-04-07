#pragma once

#include <list>
#include "i_updatable.h"

namespace context
{

struct context_info
{
    double exec_time;
    double sleep_time;
    double exec_ratio;
};

class i_context
{
public:

    virtual ~i_context(){}

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual void add_updatable( i_updatable* p_updatable ) = 0;

    virtual void remove_updatable( i_updatable* p_updatable ) = 0;

    virtual const context_info& get_context_info() const = 0;

};

typedef std::list<i_context*> contexts;

}
