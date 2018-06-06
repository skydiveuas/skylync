#ifndef EXAMPLE_TIMER_HPP
#define EXAMPLE_TIMER_HPP

#include "ITimer.hpp"

#include "TimerThread.hpp"

namespace sl
{

namespace example
{

class Timer : public ITimer
{
public:
    Timer(TimerThread& _timerThread);

    ~Timer();

    void callEvery(const Milisec interval, Task task);
    void callAfter(const Milisec timeout, Task task);

    void kill();

private:
    TimerThread& timerThread;

    TimerThread::timer_id id;
    bool running;
};

} // example

} // sl

#endif // EXAMPLE_TIMERTHREAD_HPP
