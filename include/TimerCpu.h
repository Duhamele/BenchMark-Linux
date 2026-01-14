//
// Created by duhamel on 14/01/2026.
//

#ifndef BENCHMARK_LINUX_TIMERCPU_H
#define BENCHMARK_LINUX_TIMERCPU_H
#include <cstdint>
typedef std::uint64_t time_cpu_t ;
typedef  int time_real_t;

class TimerCpu
{
    int num_cpu_;
    public:
    TimerCpu();
    time_cpu_t get_time_cpu();


    ~TimerCpu();
};

#endif //BENCHMARK_LINUX_TIMERCPU_H