//
// Created by duhamel on 14/01/2026.
//

#ifndef SIMULATION_PROJECT_MANAGER_CPU_H
#define SIMULATION_PROJECT_MANAGER_CPU_H
#include <array>
#include <mutex>
#include <vector>

enum CPU_Status
{
    FREE,
    USED,
    UNKNOW,
    NOPERM,
    NONEXISTENT,

};

class Manager_Cpu
{
private:
    std::vector<CPU_Status> status;

    public:
    Manager_Cpu();
    ~Manager_Cpu();
    static int get_cpu_free();
    static void free_cpu(int num_cpu);
    static int get_cpu_force();

};

#endif //SIMULATION_PROJECT_MANAGER_CPU_H