#ifndef ITIMER_HPP
#define ITIMER_HPP

#include <functional>
#include <exception>

namespace sl
{

class ITimer
{
public:
    typedef std::function<void(void) noexcept> Task;

    virtual ~ITimer()
    {
    }

    void callAfter(const size_t after, Task _task)
    {
        if (running)
        {
            std::runtime_error("ITimer already running.");
        }
        else
        {
            recurrnet = false;
            task = _task;
            start(after);
        }
    }

    void callEvery(const size_t interval, Task _task)
    {
        if (running)
        {
            std::runtime_error("ITimer already running.");
        }
        else
        {
            recurrnet = true;
            task = _task;
            start(interval);
        }
    }

    virtual void kill() noexcept = 0;

protected:
    virtual void start(const size_t time) = 0;

    void tick() noexcept
    {
        if (false == recurrnet)
        {
            kill();
            running = false;
        }
        task();
    }

    Task task;

    bool recurrnet { false };
    bool running { false };
};

} // sl

#endif // ITIMER_HPP
