#pragma once

#include "i_context.h"
#include "i_updatable.h"

#include <vector>
#include <thread>
#include <atomic>
#include <mutex>

namespace context
{

class context : public i_context
{
public:

    context();

    ~context();

    context( const context& ) = delete;
    context& operator=( const context& ) = delete;
    context( context && obj ) = delete;
    context& operator=( context && obj ) = delete;

    void start();

    void stop();

    void add_updatable( i_updatable* p_updatable );

    void remove_updatable( i_updatable* p_updatable );

    const context_info& get_context_info() const;

private:

    std::atomic<bool> m_running;
    
    std::thread m_thread;

    std::vector<i_updatable*> m_updatables;

    std::mutex m_updatables_mutex;

    context_info m_context_info;

    void work();

};

}
