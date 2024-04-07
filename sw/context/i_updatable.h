#pragma once

namespace context
{

class i_updatable
{
public:

    virtual ~i_updatable(){}

    virtual void update() = 0;
};

}
