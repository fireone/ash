#pragma once

#include <cmath>

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

    bool operator<(const grid_cell& other) const
    {
        return (x < other.x) || (x == other.x && y < other.y);
    }

    bool operator>(const grid_cell& other) const
    {
        return (x > other.x) || (x == other.x && y > other.y);
    }

    bool operator<=(const grid_cell& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const grid_cell& other) const
    {
        return !(*this < other);
    }
};
