#include "context.h"
#include <mutex>
#include <algorithm>

namespace context
{

context::context()
: m_running( false )
, m_thread()
, m_updatables()
, m_context_info()
{
}

context::~context()
{
    if( m_thread.joinable() )
    {
        stop();

        m_thread.join();
    }

    for( auto* p_updatable : m_updatables )
    {
        delete p_updatable;
    }
}

void context::start()
{
    if( m_running )
    {
        return;
    }

    m_running = true;

    m_thread = std::thread( &context::work, this );
}

void context::stop()
{
    m_running = false;
}

void context::add_updatable( i_updatable* p_updatable )
{
    std::lock_guard<std::mutex> guard( m_updatables_mutex );

    auto it = std::find( m_updatables.begin(), m_updatables.end(), p_updatable );

    if( it != m_updatables.end() )
    {
        return;
    }

    m_updatables.push_back( p_updatable );
}

void context::remove_updatable( i_updatable* p_updatable )
{
    std::lock_guard<std::mutex> guard( m_updatables_mutex );
    
    auto it = std::find( m_updatables.begin(), m_updatables.end(), p_updatable );

    if( it != m_updatables.end() )
    {
        m_updatables.erase( it, m_updatables.end() );
    }
}

const context_info& context::get_context_info() const
{
    return m_context_info;
}

void context::work()
{
    while( m_running )
    {
        std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );

        std::lock_guard<std::mutex> guard( m_updatables_mutex );
        for( auto* p_updatable : m_updatables )
        {
            p_updatable->update();
        }
    }
}

}
