#pragma once

#include "event/event.h"

#include "grid/grid_cell.h"

#include "utils/geo_pos.h"

#include <vector>

namespace services {

namespace route_service {

class ev_route : public ::event::event<ev_route>
{
public:

    ev_route();

    utils::geo_pos get_geo_pos() const;

private:
    utils::geo_pos m_geo_pos;
};

class ev_request_grid_route : public ::event::event<ev_request_grid_route>
{
public:

    ev_request_grid_route();

};

class ev_grid_route : public ::event::event<ev_grid_route>
{
public:

    ev_grid_route( const std::vector<grid_cell>& path );

    const std::vector<grid_cell>& get_path() const;

private:

    std::vector<grid_cell> m_path;
};

}

}
