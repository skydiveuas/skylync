#ifndef ITIMER_HPP
#define ITIMER_HPP

#include <functional>

namespace sl
{

class ITimer
{
public:
    typedef std::function<void(void)> Task;
    typedef size_t Milisec;

    virtual ~ITimer();

    virtual void callEvery(const Milisec interval, Task task) = 0;
    virtual void callAfter(const Milisec timeout, Task task) = 0;

    virtual void kill() = 0;
};

} // sl

#endif // ITIMER_HPP
