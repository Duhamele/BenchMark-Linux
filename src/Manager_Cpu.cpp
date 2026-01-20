//
// Created by duhamel on 14/01/2026.
//

#include "Manager_Cpu.h"
#include <mutex>
#include <cstring>
#include <thread>
Manager_Cpu manager_cpu_benchmark;
std::mutex mutex_manager_cpu_benchmark;
Manager_Cpu::Manager_Cpu()
{
    unsigned int n = std::thread::hardware_concurrency();
    status.resize(n);
    for (unsigned int i = 0; i < n; i++)
    {
#ifdef __linux__
        cpu_set_t mask;
        CPU_ZERO(&mask);
        CPU_SET(i, &mask);

        int ret = sched_setaffinity(0, sizeof(mask), &mask);
        if (ret == 0)
            status[i]=FREE;
        else if (errno==EPERM)
        {
            status[i]=NOPERM;
        }else
        {
            status[i]=UNKNOW;
        }
#endif
    }
}

Manager_Cpu::~Manager_Cpu()=default;

int Manager_Cpu::get_cpu_free()
{
    mutex_manager_cpu_benchmark.lock();
    for (int i = 0; i < manager_cpu_benchmark.status.size(); ++i)
    {
        if (manager_cpu_benchmark.status[i] == FREE)
        {
#ifdef __linux__
            cpu_set_t mask;
            CPU_ZERO(&mask);
            CPU_SET(i, &mask);

            int ret = sched_setaffinity(0, sizeof(mask), &mask);
            if (ret == 0)
            {
                mutex_manager_cpu_benchmark.unlock();
                return i;
            }
            if (errno==EPERM)
            {
                manager_cpu_benchmark.status[i]=NOPERM;
            }else
            {
                manager_cpu_benchmark.status[i]=UNKNOW;
            }
#endif

        }

    }
    return -1;

}

void Manager_Cpu::free_cpu(int num_cpu)
{
    mutex_manager_cpu_benchmark.lock();
    manager_cpu_benchmark.status[num_cpu]=FREE;
    mutex_manager_cpu_benchmark.unlock();

}

int Manager_Cpu::get_cpu_force()
{
    mutex_manager_cpu_benchmark.lock();
    for (int i = 0; i < manager_cpu_benchmark.status.size(); ++i)
    {
        if (manager_cpu_benchmark.status[i] != USED)
        {
#ifdef __linux__
            cpu_set_t mask;
            CPU_ZERO(&mask);
            CPU_SET(i, &mask);

            int ret = sched_setaffinity(0, sizeof(mask), &mask);
            if (ret == 0)
            {
                mutex_manager_cpu_benchmark.unlock();
                return i;
            }
            if (errno==EPERM)
            {
                manager_cpu_benchmark.status[i]=NOPERM;
            }else
            {
                manager_cpu_benchmark.status[i]=UNKNOW;
            }
#endif

        }

    }
    return -1;
}

