#pragma once

#include "gnss_sensor.h"

#include <cstdint>


#include "context/i_updatable.h"
#include "context/i_context.h"

namespace sensors
{

namespace gnss
{

class ublox_zed_f9r : public gnss_sensor, private context::i_updatable
{
public:
    ublox_zed_f9r( const std::string& device_path, context::i_context* p_context );

    ~ublox_zed_f9r();

    const std::string& get_name() const;

    // TODO - getters should be events instead
    double get_lng() const;

    double get_lat() const;

    inline static const std::string name = "ublox_zed_f9r";

private:
    
    context::i_context* mp_context;
    
    double m_lng;

    double m_lat;

    int m_serial_port;
    
    void update();

    bool is_ublox_header( uint8_t* buf, size_t& read_bytes );

    uint16_t get_ublox_msg_type( uint8_t* buf, size_t& read_bytes );

    uint16_t get_ublox_payload_length( uint8_t* buf, size_t& read_bytes );

    void parse_ubx_nav_pvat( uint8_t* buf, size_t& read_bytes );

    void parse_ubx_nav_status( uint8_t* buf, size_t& read_bytes );
};

}

}

