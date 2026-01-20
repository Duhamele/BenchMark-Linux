/**
* @file TimerCpu.h
 * @brief Definition of the TimerCpu class
 * @author duhamel
 * @date 14/01/2026
 */

#ifndef BENCHMARK_LINUX_TIMERCPU_H
#define BENCHMARK_LINUX_TIMERCPU_H

#include <chrono>
#include <bits/posix2_lim.h>

/**
 * @struct time_cpu_t
 * @brief CPU time structure
 */
typedef timespec time_cpu_t ;

/**
 * @struct time_real_t
 * @brief Real time structure
 */
typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_real_t;

/**
 * @struct Duration_Timer_Cpu
 * @brief CPU duration structure
 */
struct Duration_Timer_Cpu
{
    long long int cpu_duration; /**< CPU duration */
    long long int real_duration; /**< Real duration */
};

/**
 * @class TimerCpu
 * @brief Class for managing a timer
 */
class TimerCpu
{
    int num_cpu_; /**< Number of CPUs */
    time_cpu_t start_time_; /**< Start time in CPU */
    time_cpu_t stop_time_; /**< Stop time in CPU */
    time_real_t start_time_real_; /**< Start time in real time */
    time_real_t stop_time_real_; /**< Stop time in real time */

public:
    /**
     * @brief Constructor of the TimerCpu class
     */
    TimerCpu();

    /**
     * @brief Start the timer
     */
    void start();

    /**
     * @brief Stop the timer
     */
    void stop();

    /**
     * @brief Get the duration of the timer
     * @return The duration of the timer
     */
    Duration_Timer_Cpu dure();

    /**
     * @brief Destructor of the TimerCpu class
     */
    ~TimerCpu()=default;
};

#endif //BENCHMARK_LINUX_TIMERCPU_H