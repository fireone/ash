#pragma once

#include "utils/i_map.h"
#include "utils/point_2d.h"
#include "grid_map.h"

class grid_map_builder {
public:
    grid_map_builder(double resolution, int max_width_cells = 200, int max_height_cells = 200);

    grid_map* build_from( const i_map* map_ptr );

private:
    double m_resolution; // meters per cell
    int m_width;
    int m_height;
    //TODO replace with point_2d
    double m_origin_x;
    double m_origin_y;

    std::pair<int, int> world_to_grid(const point_2d& point) const;
    void rasterize_polygon(grid_map& grid_map, const polygon& poly, cell_type fill_type);
};
