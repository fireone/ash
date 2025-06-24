#pragma once

#include <vector>
#include "point_2d.h"

struct AABB {
    double minX, maxX, minY, maxY;

    AABB()
    : minX( 0.0 )
    , minY( 0.0 )
    , maxX( 0.0 )
    , maxY( 0.0 )

    {

    }

    AABB( point_2d p1, point_2d p2 )
    {
        minX = std::min<double>( p1.x, p2.x );
        minY = std::min<double>( p1.y, p2.y );
        maxX = std::max<double>( p1.x, p2.x );
        maxX = std::max<double>( p1.y, p2.y );
    }

    void expandToInclude(const point_2d& pt)
    {
        minX = std::min(minX, pt.x);
        maxX = std::max(maxX, pt.x);
        minY = std::min(minY, pt.y);
        maxY = std::max(maxY, pt.y);
    }
};

class polygon
{
public:
    enum class ContainmentMode {
        Inclusive,
        Strict
    };

    void addPoint(double x, double y);
    void addPoint(const point_2d& point);
    void close();

    bool contains(const point_2d& point, ContainmentMode mode = ContainmentMode::Inclusive) const;
    bool intersectsSegment(const point_2d& a, const point_2d& b) const;
    std::vector<point_2d> getLineIntersections(const point_2d& p1, const point_2d& p2) const;

    const AABB& boundingBox() const { return m_boundingBox; }
    const std::vector<point_2d>& vertices() const { return m_vertices; }

    void setContainmentMode(ContainmentMode mode);
    ContainmentMode containmentMode() const;

    const size_t size() const;

private:
    std::vector<point_2d> m_vertices;
    AABB m_boundingBox;
    bool m_isClosed = false;

    ContainmentMode m_mode;
};
