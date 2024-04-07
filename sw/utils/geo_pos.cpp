#include "geo_pos.h"

namespace utils
{

geo_pos::geo_pos()
: m_lat( 0 )
, m_lng( 0 )
{
}

geo_pos::geo_pos( double lat, double lng )
: m_lat( lat )
, m_lng( lng )
{
}

double geo_pos::get_lat() const
{
    return m_lat;
}

double geo_pos::get_lng() const
{
    return m_lng;
}

}
