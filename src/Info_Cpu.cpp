//
// Created by duhamel on 15/01/2026.
//

#include "Info_Cpu.h"

/*  Linux  */

#include <fstream>
#include <string>
#include <sys/sysinfo.h>

#include <thread>

std::string cpu_model_linux_() {
    std::ifstream f("/proc/cpuinfo");
    std::string line;
    while (std::getline(f, line)) {
        if (line.find("model name") != std::string::npos ||
            line.find("Processor") != std::string::npos)
            return line.substr(line.find(':') + 2);
    }
    return "Unknown";
}


unsigned long long Info_Cpu::get_ram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram * info.mem_unit;
}
int Info_Cpu::get_num_cores()
{
    return std::thread::hardware_concurrency();
}

std::string Info_Cpu::get_name_cpu()
{
#ifdef __linux__
    return cpu_model_linux_();
    #else
#warning "Not implemented for this platform : Info_Cpu::get_name_cpu()"
    return "Systems unsupported";
#endif

}
