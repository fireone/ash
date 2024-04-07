#pragma once

#include "services/i_service.h"

#include <map>
#include <string>

namespace builder
{

namespace services
{

typedef std::map<std::string, std::string> parameter_list;

class i_service_builder
{
public:
    virtual ~i_service_builder(){}

    virtual ::services::i_service* build( const parameter_list& parameters ) = 0;

    virtual const std::string& get_service_name() const = 0;
};

}

}
