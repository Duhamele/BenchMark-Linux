include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(BenchMark-Linux STATIC TimerCpu.cpp
        Manager_Cpu.cpp
        Manager_Cpu.h
        Info_Cpu.cpp
        Info_Cpu.h)