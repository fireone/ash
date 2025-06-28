#pragma once
#include "utils/point_2d.h"

#include <cmath>
#include <vector>

enum class cell_type {
    free,
    obstacle,
    soft_obstacle
};

struct grid_cell {
    int x, y;

    grid_cell(int _x, int _y ) : x(_x), y(_y){}
    grid_cell() : x( 0 ), y( 0 ){}

    bool is_adjacent( const grid_cell& other ) const
    {
        int dx( std::abs( x - other.x ) );
        int dy( std::abs( y - other.y ) );

        return ( dx + dy ) == 1;
    }

    bool operator==(const grid_cell& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const grid_cell& other) const
    {
        return x != other.x || y != other.y;
    }
};

class grid_map {
public:
    grid_map(int width, int height, double resolution, const point_2d& origin);
    grid_map(int width, int height);

    void set_obstacle(int x, int y);
    bool is_free(int x, int y) const;
    bool is_obstacle(int x, int y) const;
    bool is_soft_obstacle(int x, int y) const;
    bool is_strictly_free(int x, int y) const;
    void set_free(int x, int y);
    void set_soft_obstacle(int x, int y);
    int get_width() const { return m_width; }
    int get_height() const { return m_height; }
    bool in_bounds(int x, int y) const;
    cell_type get(int x, int y) const;
    point_2d grid_to_world(int x, int y) const {
        double wx = m_origin.x + x * m_resolution + m_resolution / 2.0;
        double wy = m_origin.y + y * m_resolution + m_resolution / 2.0;
        return point_2d{wx, wy};
    }

    std::pair<int, int> world_to_grid(const point_2d& point) const {
        int gx = static_cast<int>((point.x - m_origin.x) / m_resolution);
        int gy = static_cast<int>((point.y - m_origin.y) / m_resolution);
        return {gx, gy};
    }

    static std::vector<point_2d> convert_path_to_world( const std::vector<grid_cell>& grid_path,
                                                        const grid_map& grid );

private:
    int m_width;
    int m_height;
    double m_resolution;
    point_2d m_origin;
    std::vector<std::vector<cell_type>> m_grid;
};
