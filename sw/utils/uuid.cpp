#include "uuid.h"

#include <iomanip>
#include <random>

namespace utils 
{

std::ostream &operator<<(std::ostream &s, const uuid &uuid)
{
	std::ios_base::fmtflags currentFlag( s.flags() ); 
	
    s   << std::hex << std::setfill('0')
	    << std::setw(2) << (int)uuid.m_bytes[0]
	    << std::setw(2) << (int)uuid.m_bytes[1]
		<< std::setw(2) << (int)uuid.m_bytes[2]
		<< std::setw(2) << (int)uuid.m_bytes[3]
		<< "-"
		<< std::setw(2) << (int)uuid.m_bytes[4]
		<< std::setw(2) << (int)uuid.m_bytes[5]
		<< "-"
		<< std::setw(2) << (int)uuid.m_bytes[6]
		<< std::setw(2) << (int)uuid.m_bytes[7]
		<< "-"
		<< std::setw(2) << (int)uuid.m_bytes[8]
		<< std::setw(2) << (int)uuid.m_bytes[9]
		<< "-"
		<< std::setw(2) << (int)uuid.m_bytes[10]
		<< std::setw(2) << (int)uuid.m_bytes[11]
		<< std::setw(2) << (int)uuid.m_bytes[12]
		<< std::setw(2) << (int)uuid.m_bytes[13]
		<< std::setw(2) << (int)uuid.m_bytes[14]
		<< std::setw(2) << (int)uuid.m_bytes[15];
	
    s.flags( currentFlag );
	
    return s;
}

unsigned char hexToChar( char ch )
{
	// 0-9
	if (ch > 47 && ch < 58)
		return ch - 48;

	// a-f
	if (ch > 96 && ch < 103)
		return ch - 87;

	// A-F
	if (ch > 64 && ch < 71)
		return ch - 55;

	return 0;
}

unsigned char str_to_hex( const std::string& str, size_t offset )
{
    return hexToChar( str[ offset ] ) * 16 + hexToChar( str[ ++offset ] );
}

uuid::uuid()
{
	static std::random_device dev;
    static std::mt19937 rng( dev() );

    std::uniform_int_distribution<int> dist( 0, 255 );

    m_bytes[ 0 ] = dist( rng );
    m_bytes[ 1 ] = dist( rng );
    m_bytes[ 2 ] = dist( rng );
    m_bytes[ 3 ] = dist( rng );

    m_bytes[ 4 ] = dist( rng );
    m_bytes[ 5 ] = dist( rng );

    m_bytes[ 6 ] = dist( rng );
    m_bytes[ 7 ] = dist( rng );

    m_bytes[ 8 ] = dist( rng );
    m_bytes[ 9 ] = dist( rng );
    
    m_bytes[ 10 ] = dist( rng );
    m_bytes[ 11 ] = dist( rng );
    m_bytes[ 12 ] = dist( rng );
    m_bytes[ 13 ] = dist( rng );
    m_bytes[ 14 ] = dist( rng );
    m_bytes[ 15 ] = dist( rng );

}

uuid::uuid( const std::string& str )
{    
    m_bytes[ 0 ] = str_to_hex( str, 0 );
    m_bytes[ 1 ] = str_to_hex( str, 2 );
    m_bytes[ 2 ] = str_to_hex( str, 4 );
    m_bytes[ 3 ] = str_to_hex( str, 6 );

    m_bytes[ 4 ] = str_to_hex( str, 9 );
    m_bytes[ 5 ] = str_to_hex( str, 11 );

    m_bytes[ 6 ] = str_to_hex( str, 14 );
    m_bytes[ 7 ] = str_to_hex( str, 16 );

    m_bytes[ 8 ] = str_to_hex( str, 19 );
    m_bytes[ 9 ] = str_to_hex( str, 21 );
    
    m_bytes[ 10 ] = str_to_hex( str, 24 );
    m_bytes[ 11 ] = str_to_hex( str, 26 );
    m_bytes[ 12 ] = str_to_hex( str, 28 );
    m_bytes[ 13 ] = str_to_hex( str, 30 );
    m_bytes[ 14 ] = str_to_hex( str, 32 );
    m_bytes[ 15 ] = str_to_hex( str, 34 );

}

bool uuid::operator==(const uuid &other) const
{
	return m_bytes == other.m_bytes;
}

bool uuid::operator!=(const uuid &other) const
{
	return !( ( *this ) == other );
}

}
