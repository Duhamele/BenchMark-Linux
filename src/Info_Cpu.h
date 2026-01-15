//
// Created by duhamel on 15/01/2026.
//

#ifndef SIMULATION_PROJECT_INFO_CPU_H
#define SIMULATION_PROJECT_INFO_CPU_H
#include <string>


class Info_Cpu
{
public:
    static std::string get_name_cpu();
    static unsigned long long get_ram();
    static int get_num_cores();

};


#endif //SIMULATION_PROJECT_INFO_CPU_H