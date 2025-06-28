#include "grid_map.h"

grid_map::grid_map(int width, int height, double resolution, const point_2d &origin)
    : m_width(width), m_height(height), m_resolution( resolution), m_origin( origin ), m_grid(height, std::vector<cell_type>(width, cell_type::obstacle))
{

}

grid_map::grid_map(int width, int height)
    : m_width(width), m_height(height), m_grid(height, std::vector<cell_type>(width, cell_type::obstacle)) {}

void grid_map::set_obstacle(int x, int y) {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        m_grid[y][x] = cell_type::obstacle;
    }
}

bool grid_map::is_free(int x, int y) const {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        return false;
    return m_grid[y][x] == cell_type::free || m_grid[y][x] == cell_type::soft_obstacle;
}

bool grid_map::is_obstacle(int x, int y) const
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        return false;
    return m_grid[y][x] == cell_type::obstacle;
}

bool grid_map::is_soft_obstacle(int x, int y) const
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        return false;
    return m_grid[y][x] == cell_type::soft_obstacle;
}

bool grid_map::is_strictly_free(int x, int y) const {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        return false;
    return m_grid[y][x] == cell_type::free;
}

void grid_map::set_free(int x, int y)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        return;
    }
    m_grid[y][x] = cell_type::free;
}

void grid_map::set_soft_obstacle(int x, int y)
{
    if( !in_bounds( x, y ) )
    {
        return;
    }

    m_grid[y][x] = cell_type::soft_obstacle;
}

bool grid_map::in_bounds(int x, int y) const
{
    return x >= 0 && y >= 0 && x < m_width && y < m_height;
}

cell_type grid_map::get(int x, int y) const
{
    return m_grid[y][x];
}

std::vector<point_2d> grid_map::convert_path_to_world(const std::vector<grid_cell> &grid_path, const grid_map &grid)
{
    std::vector<point_2d> world_path;
    for (const auto& cell : grid_path) {
        world_path.push_back(grid.grid_to_world(cell.x, cell.y));
    }
    return world_path;
}
