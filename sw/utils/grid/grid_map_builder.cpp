#include "grid_map_builder.h"
#include <algorithm>
#include <cmath>

grid_map_builder::grid_map_builder(double resolution, int max_width_cells, int max_height_cells)
    : m_resolution(resolution), m_width(max_width_cells), m_height(max_height_cells),
    m_origin_x(0.0), m_origin_y(0.0) {}

std::pair<int, int> grid_map_builder::world_to_grid(const point_2d& point) const {
    int gx = static_cast<int>(std::floor((point.x - m_origin_x) / m_resolution));
    int gy = static_cast<int>(std::floor((point.y - m_origin_y) / m_resolution));
    return {gx, gy};
}

void grid_map_builder::rasterize_polygon(grid_map& grid_map, const polygon& poly, cell_type fill_type) {

    // Very basic polygon fill using bounding box scan — can be improved
    double min_x = poly.vertices()[0].x, max_x = poly.vertices()[0].x;
    double min_y = poly.vertices()[0].y, max_y = poly.vertices()[0].y;
    for (const auto& pt : poly.vertices()) {
        min_x = std::min(min_x, pt.x);
        max_x = std::max(max_x, pt.x);
        min_y = std::min(min_y, pt.y);
        max_y = std::max(max_y, pt.y);
    }

    auto [gx_min, gy_min] = world_to_grid( point_2d{min_x, min_y} );
    auto [gx_max, gy_max] = world_to_grid( point_2d{max_x, max_y} );

    for (int y = gy_min; y <= gy_max; ++y) {
        for (int x = gx_min; x <= gx_max; ++x) {
            // Center of cell in world coords
            double cx = x * m_resolution + m_resolution / 2.0;
            double cy = y * m_resolution + m_resolution / 2.0;

            point_2d p{cx, cy};

            // Point-in-polygon test
            int crossings = 0;
            size_t count = poly.size();
            for (size_t i = 0; i < count; ++i) {
                const point_2d& a = poly.vertices()[i];
                const point_2d& b = poly.vertices()[(i + 1) % count];
                if (((a.y > p.y) != (b.y > p.y)) &&
                    (p.x < (b.x - a.x) * (p.y - a.y) / (b.y - a.y + 1e-9) + a.x)) {
                    crossings++;
                }
            }

            if (crossings % 2 == 1) {
                // Inside polygon
                if (x >= 0 && x < grid_map.get_width() && y >= 0 && y < grid_map.get_height()) {
                    if (fill_type == cell_type::obstacle)
                        grid_map.set_obstacle(x, y);
                }
            }
        }
    }
}

grid_map* grid_map_builder::build_from(const i_map* map_ptr)
{
    const polygon& boundary = map_ptr->get_boundary();
    const auto& obstacles = map_ptr->get_obstacles();
    const auto& soft_obstacles = map_ptr->get_soft_obstacles();

    // Step 1: Compute bounding box of boundary polygon
    double min_x = std::numeric_limits<double>::max();
    double min_y = std::numeric_limits<double>::max();
    double max_x = std::numeric_limits<double>::lowest();
    double max_y = std::numeric_limits<double>::lowest();

    for (const auto& pt : boundary.vertices()) {
        min_x = std::min(min_x, pt.x);
        min_y = std::min(min_y, pt.y);
        max_x = std::max(max_x, pt.x);
        max_y = std::max(max_y, pt.y);
    }

    // Step 2: Compute grid dimensions
    int grid_width  = static_cast<int>(std::ceil((max_x - min_x) / m_resolution));
    int grid_height = static_cast<int>(std::ceil((max_y - min_y) / m_resolution));

    // Step 3: Create grid with default "Obstacle"
    grid_map* grid = new grid_map(grid_width, grid_height, m_resolution, point_2d{min_x, min_y});

    // Step 4: Fill in cell types
    for (int y = 0; y < grid_height; ++y) {
        for (int x = 0; x < grid_width; ++x) {
            double cx = min_x + x * m_resolution + m_resolution / 2.0;
            double cy = min_y + y * m_resolution + m_resolution / 2.0;
            point_2d cell_center{cx, cy};

            // 1. Skip if outside the boundary
            if (!boundary.contains(cell_center))
                continue;

            // 2. Check if inside hard obstacle
            bool is_hard_obstacle = false;
            for (const auto& obs : obstacles) {
                if (obs.contains(cell_center)) {
                    is_hard_obstacle = true;
                    break;
                }
            }

            if (is_hard_obstacle) {
                // leave as default "Obstacle"
                continue;
            }

            // 3. Check if inside soft obstacle
            bool is_soft_obstacle = false;
            for (const auto& soft : soft_obstacles) {
                if (soft.contains(cell_center)) {
                    is_soft_obstacle = true;
                    break;
                }
            }

            if (is_soft_obstacle) {
                grid->set_soft_obstacle(x, y);
            } else {
                grid->set_free(x, y);
            }
        }
    }

    return grid;
}
