//
// Created by duhamel on 16/01/2026.
//

#ifndef SIMULATION_PROJECT_BENCHMARKUNIT_H
#define SIMULATION_PROJECT_BENCHMARKUNIT_H
#include "BrenchMark.h"

#define BENCHMARK_UNIT(function,name,category) BenchMarkTestUnitaire ##name##category =\
    BenchMarkRegister::add_benchmark_test( \
        BenchMarkTestUnitaire( #name, __LINE__ ,__FILE__,#function),#category);


template<typename T>
class BenchMarkTestUnitaire:BenchMarkTest
{


    public:
    using BenchFn = T(*)();
    BenchMarkTestUnitaire(std::string name,int line,std::string file,BenchFn
    function):BenchMarkTest(name,line,file),function(function)
    {
    }
private:
    BenchFn function;

};

#endif //SIMULATION_PROJECT_BENCHMARKUNIT_H