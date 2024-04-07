#include "ublox_zed_f9r.h"

#include <fcntl.h> 
#include <cstring>
#include <termios.h>
#include <unistd.h> 
#include <iomanip>
#include <iostream>

#include <thread>

namespace sensors
{

namespace gnss
{

#define HEX( s, x ) std::setw( s * 2 ) << std::setfill('0') << std::hex << (int)( x )

#define UBX_SYNC_CH_1 0xb5
#define UBX_SYNC_CH_2 0x62

#define UBX_NAV_STATUS 0x0103
#define UBX_NAV_PVAT   0x0117

bool configure_serial( int serial_port )
{
  struct termios tty;

  if( tcgetattr( serial_port, &tty ) != 0 )
  {
      std::cout << "Error " << errno << " from tcgetattr: " << strerror( errno ) << std::endl;
      
      return false;
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
  tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
  tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO; // Disable echo
  tty.c_lflag &= ~ECHOE; // Disable erasure
  tty.c_lflag &= ~ECHONL; // Disable new-line echo
  tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

  tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
  tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

  tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  cfsetispeed( &tty, B115200 );
  cfsetospeed( &tty, B115200 );

    // Save tty settings, also checking for error
    if( tcsetattr( serial_port, TCSANOW, &tty ) != 0 )
    {
        std::cout << "Error " << errno << " from tcsetattr: " << std::strerror( errno ) << std::endl;
        
        return false;
    }

    return true;
}

ublox_zed_f9r::ublox_zed_f9r( const std::string& device_path, context::i_context* p_context )
: mp_context( p_context )
, m_lng( 0.0 )
, m_lat( 0.0 )
{
    m_serial_port = open( device_path.c_str(), O_RDWR );

    if( configure_serial( m_serial_port ) )
    {    
        mp_context->add_updatable( this );

        mp_context->start();
    }
}

ublox_zed_f9r::~ublox_zed_f9r()
{
    mp_context->remove_updatable( this );
}

const std::string& ublox_zed_f9r::get_name() const
{
   return name;
}

double ublox_zed_f9r::get_lng() const
{
    return m_lng;
}

double ublox_zed_f9r::get_lat() const
{
    return m_lat;
}

bool ublox_zed_f9r::is_ublox_header( uint8_t* buf, size_t& read_bytes )
{
    read_bytes += 2;
    
    return( buf[ 0 ] == UBX_SYNC_CH_1 && buf[ 1 ] == UBX_SYNC_CH_2 );
}

uint16_t ublox_zed_f9r::get_ublox_msg_type( uint8_t* buf, size_t& read_bytes )
{
    read_bytes += 2;
    
    return( (uint16_t)buf[ 0 ] << 8 | (uint16_t)buf[ 1 ] );
}

uint16_t ublox_zed_f9r::get_ublox_payload_length( uint8_t* buf, size_t& read_bytes )
{
    read_bytes += 2;
    
    return( (uint16_t)buf[ 1 ] << 8 | (uint16_t)buf[ 0 ] );
}

void ublox_zed_f9r::parse_ubx_nav_pvat( uint8_t* buf, size_t& read_bytes )
{
    read_bytes += get_ublox_payload_length( buf, read_bytes );
    
    int32_t lng = 0;
    int32_t lat = 0;
            
    lng = ((int32_t)buf[33]<<24) |
          ((int32_t)buf[32]<<16) |
          ((int32_t)buf[31]<<8) |
          ((int32_t)buf[30]);
          
    lat = ((int32_t)buf[37]<<24) |
          ((int32_t)buf[36]<<16) |
          ((int32_t)buf[35]<<8) |
          ((int32_t)buf[34]);

    m_lng = static_cast<double>( lng );
    m_lat = static_cast<double>( lat );
}

void ublox_zed_f9r::parse_ubx_nav_status( uint8_t* buf, size_t& read_bytes )
{
    read_bytes += get_ublox_payload_length( buf, read_bytes );
    
    uint8_t gps_fix = buf[ 6 ];
}

void ublox_zed_f9r::update()
{
    unsigned char read_buf[ 1024 ];
         
    size_t num_bytes = read( m_serial_port, &read_buf, sizeof( read_buf ) );

    if( num_bytes < 0 )
    {
        std::cout << "Error reading: " << std::strerror( errno ) << std::endl;
      
        return;
    }
    
    size_t read_bytes( 0 );
  
    if( is_ublox_header( read_buf, read_bytes ) )
    {
        uint16_t msg_type( get_ublox_msg_type( &read_buf[ read_bytes ], read_bytes ) );
        
        switch( msg_type )
        {
            case UBX_NAV_PVAT:
                parse_ubx_nav_pvat( &read_buf[ read_bytes ], read_bytes );
            break;
            
            case UBX_NAV_STATUS:
                parse_ubx_nav_status( &read_buf[ read_bytes ], read_bytes );
            break;
      
            default:
                std::cout << "No UBX message parser for message:" << std::endl;
                std::cout <<  HEX( 2, msg_type ) << std::endl;
            break;      
        }
        
        //skip checksum for now :)
        read_bytes += 2;
    }
}

}

}
