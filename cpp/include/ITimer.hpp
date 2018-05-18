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

    virtual void callAfter(const size_t after, Task task) = 0;

    virtual void callEvery(const size_t interval, Task task) = 0;

    virtual void kill() noexcept = 0;
};

} // sl

#endif // ITIMER_HPP
