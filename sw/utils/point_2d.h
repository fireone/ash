#pragma once

#include <math.h>

struct point_2d {
    double x, y;

    // Constructor
    explicit point_2d(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    bool operator==(const point_2d& other) const {
        constexpr double EPS = 1e-9;
        return std::abs(x - other.x) < EPS && std::abs(y - other.y) < EPS;
    }

    bool operator!=(const point_2d& other) const {
        return !(*this == other);
    }


    // Basic arithmetic
    point_2d operator+(const point_2d& other) const {
        return point_2d(x + other.x, y + other.y);
    }

    point_2d operator-(const point_2d& other) const {
        return point_2d(x - other.x, y - other.y);
    }

    point_2d operator*(double scalar) const {
        return point_2d(x * scalar, y * scalar);
    }

    double dot(const point_2d& other) const {
        return x * other.x + y * other.y;
    }

    double cross(const point_2d& other) const {
        return x * other.y - y * other.x;
    }

    double length() const {
        return std::sqrt(x * x + y * y);
    }

    double lengthSquared() const {
        return x * x + y * y;
    }

    point_2d normalized() const {
        double len = length();
        return len == 0 ? point_2d(0, 0) : point_2d(x / len, y / len);
    }
};

struct LineSegment {
    point_2d start;
    point_2d end;

    enum SEGMENT_TYPE
    {
        PATH,
        CONNECTION,
    } type;

    LineSegment() = default;
    LineSegment(const point_2d& s, const point_2d& e, SEGMENT_TYPE t=PATH) : start(s), end(e), type( t ) {}

    double lengthSquared() const {
        return (end - start).lengthSquared();
    }

    double length() const {
        return std::sqrt(lengthSquared());
    }
};


