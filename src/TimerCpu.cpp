//
// Created by duhamel on 14/01/2026.
//
#include "TimerCpu.h"

#include <chrono>

/**
 * @brief Constructor of the TimerCpu class
 */
TimerCpu::TimerCpu()
{   //TODO initail num_cpu
    start_time_ = {0, 0};
    stop_time_ = {0, 0};
    start_time_real_ = std::chrono::time_point<std::chrono::high_resolution_clock>();
    stop_time_real_ = std::chrono::time_point<std::chrono::high_resolution_clock>();
}

/**
 * @brief Start the timer
 */
void TimerCpu::start()
{
    start_time_real_=std::chrono::high_resolution_clock::now();
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start_time_);
}
/**
 * @brief Stop the timer
 */
void TimerCpu::stop()
{
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &stop_time_);
    stop_time_real_=std::chrono::high_resolution_clock::now();
}
/**
 * @brief Get the duration of the timer
 * @return The duration of the timer
 */
Duration_Timer_Cpu TimerCpu::dure()
{
    // Calculate the duration in CPU time
    long long int cpu_duration = (stop_time_.tv_sec - start_time_.tv_sec) * 1000000 + (stop_time_.tv_nsec - start_time_.tv_nsec) / 1000;

    // Calculate the duration in real time
    long long int real_duration = (stop_time_real_.time_since_epoch().count() - start_time_real_.time_since_epoch().count()) * 1000000 / std::chrono::high_resolution_clock::period::den;

    // Get the duration as a structure
    Duration_Timer_Cpu duration = {cpu_duration, real_duration};
    return duration;
}