#include "example/Timer.hpp"

#include <exception>

using sl::example::Timer;

Timer::Timer(sl::example::TimerThread& _timerThread):
    timerThread(_timerThread),
    running(false)
{
}

Timer::~Timer()
{
    kill();
}

void Timer::callEvery(const Milisec interval, Task task)
{
    if (false == running)
    {
        id = timerThread.setInterval(task, interval);
        running = true;
    }
    else
    {
        throw std::logic_error("Trying to start timer when it is stil running");
    }
}

void Timer::callAfter(const Milisec timeout, Task task)
{
    if (false == running)
    {
        id = timerThread.setInterval(task, timeout);
        running = true;
    }
    else
    {
        throw std::logic_error("Trying to start timer when it is stil running");
    }
}

#include <iostream>

void Timer::kill()
{
    if (running)
    {
        timerThread.clearTimer(id);
        running = false;
    }
}
