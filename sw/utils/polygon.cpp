#include "polygon.h"
#include <stdexcept>
#include <cmath>


// Helper to check and compute intersection point of two line segments
static bool segmentsIntersect(
    const point_2d& p1, const point_2d& p2,
    const point_2d& q1, const point_2d& q2,
    point_2d& intersection)
{
    point_2d r = p2 - p1;
    point_2d s = q2 - q1;
    double rxs = r.cross(s);
    double qpxr = (q1 - p1).cross(r);

    if (std::abs(rxs) < 1e-10 && std::abs(qpxr) < 1e-10) {
        // Colinear — optionally handle this case
        return false;
    }
    if (std::abs(rxs) < 1e-10) {
        // Parallel
        return false;
    }

    double t = (q1 - p1).cross(s) / rxs;
    double u = (q1 - p1).cross(r) / rxs;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        intersection = p1 + r * t;
        return true;
    }
    return false;
}

bool pointOnSegment(const point_2d& p, const point_2d& a, const point_2d& b)
{
    const double EPS = 1e-9;

    double cross = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
    if (std::abs(cross) > EPS)
        return false;

    double dot = (p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y);
    double lenSq = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    return dot >= -EPS && dot <= lenSq + EPS;
}

void polygon::addPoint( double x, double y )
{
    addPoint( point_2d( x, y ) );
}


void polygon::addPoint(const point_2d& point)
{
    m_vertices.push_back(point);
    if (m_vertices.size() == 1) {
        m_boundingBox = AABB(point, point);
    } else {
        m_boundingBox.expandToInclude(point);
    }
}

void polygon::close()
{
    m_isClosed = true;
}

bool polygon::contains(const point_2d& point, ContainmentMode m_mode) const
{
    if (!m_isClosed)
        throw std::runtime_error("Cannot test containment on an open polygon.");

    // Bounding box check for early rejection
    if (point.x < m_boundingBox.minX || point.x > m_boundingBox.maxX ||
        point.y < m_boundingBox.minY || point.y > m_boundingBox.maxY) {
        return false;
    }

    // If Inclusive mode: check if point lies exactly on any edge
    if (m_mode == ContainmentMode::Inclusive) {
        for (size_t i = 0; i < m_vertices.size(); ++i) {
            const point_2d& a = m_vertices[i];
            const point_2d& b = m_vertices[(i + 1) % m_vertices.size()];
            if (pointOnSegment(point, a, b)) {
                return true;
            }
        }
    }

    // Ray casting algorithm
    int crossings = 0;
    size_t count = m_vertices.size();
    for (size_t i = 0; i < count; ++i) {
        const point_2d& a = m_vertices[i];
        const point_2d& b = m_vertices[(i + 1) % count];

        if (((a.y > point.y) != (b.y > point.y)) &&
            (point.x < (b.x - a.x) * (point.y - a.y) / (b.y - a.y + 1e-12) + a.x)) {
            ++crossings;
        }
    }

    return (crossings % 2) == 1;
}

std::vector<point_2d> polygon::getLineIntersections(const point_2d& p1, const point_2d& p2) const
{
    std::vector<point_2d> intersections;

    for (size_t i = 0; i < m_vertices.size(); ++i) {
        const point_2d& a = m_vertices[i];
        const point_2d& b = m_vertices[(i + 1) % m_vertices.size()];

        point_2d hit;
        if (segmentsIntersect(p1, p2, a, b, hit)) {
            intersections.push_back(hit);
        }
    }

    return intersections;
}

void polygon::setContainmentMode(ContainmentMode mode)
{
    m_mode = mode;
}

polygon::ContainmentMode polygon::containmentMode() const
{
    return m_mode;
}

const size_t polygon::size() const
{
    return m_vertices.size();
}

bool polygon::intersectsSegment(const point_2d& a, const point_2d& b) const
{
    size_t count = m_vertices.size();
    for (size_t i = 0; i < count; ++i) {
        const point_2d& p1 = m_vertices[i];
        const point_2d& p2 = m_vertices[(i + 1) % count];

        point_2d intersection;
        if (segmentsIntersect(a, b, p1, p2, intersection)) {
            return true;
        }
    }
    return false;
}
