#include "environment.h"

using namespace services::simulator_service;

environment::environment( i_map* map_ptr )
    : m_map_ptr( map_ptr )
{}

const i_map *environment::get_map() const
{
    return m_map_ptr;
}