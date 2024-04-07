#pragma once

#include <string>
#include <array>

namespace utils
{

class uuid
{
public:
	uuid();
	uuid( const std::string& str );
	uuid &operator=( const uuid &other ) = default;
	
	bool operator==( const uuid &other ) const;
	bool operator!=( const uuid &other ) const;

private:
	std::array< unsigned char, 16 > m_bytes;

	friend std::ostream &operator<<( std::ostream &s, const uuid &uuid );
};

}
