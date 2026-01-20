//
// Created by duhamel on 14/01/2026.
//

#ifndef BENCHMARK_LINUX_TIMERCPU_H
#define BENCHMARK_LINUX_TIMERCPU_H
#include <chrono>
#include <bits/posix2_lim.h>

typedef timespec time_cpu_t ;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_real_t;
struct Duration_Timer_Cpu;
class TimerCpu
{
    int num_cpu_;
    time_cpu_t start_time_;
    time_cpu_t stop_time_;
    time_real_t start_time_real_;
    time_real_t stop_time_real_;
    public:
    TimerCpu();
    void start();
    void stop();
    Duration_Timer_Cpu dure();



    ~TimerCpu()=default;
};

struct Duration_Timer_Cpu
{
    long long int cpu_duration;
    long long int real_duration;

};

#endif //BENCHMARK_LINUX_TIMERCPU_H