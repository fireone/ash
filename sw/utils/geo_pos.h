#pragma once

namespace utils
{

class geo_pos
{
public:

    geo_pos();

    geo_pos( double lat, double lng );

    double get_lat() const;

    double get_lng() const;

private:
    double m_lat;

    double m_lng;
};

}

