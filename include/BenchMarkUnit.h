//
// Created by duhamel on 16/01/2026.
//

#ifndef SIMULATION_PROJECT_BENCHMARKUNIT_H
#define SIMULATION_PROJECT_BENCHMARKUNIT_H
#include "BrenchMark.h"

#define BENCHMARK_UNIT(function,name,category) BenchMarkTest *   _##name##category =\
    BenchMarkRegister::add_benchmark_test( \
       new BenchMarkTestUnitaire( #name, __LINE__ ,__FILE__, function),#category);


template<typename T>
class BenchMarkTestUnitaire: public BenchMarkTest
{


    public:
    using BenchFn = T(*)();
    BenchMarkTestUnitaire(const std::string& name, const int line, const std::string& file,BenchFn
    function):BenchMarkTest(name,line,file),function(function)
    {
    }
    void run() override
    {

    }
    ~BenchMarkTestUnitaire()=default;
protected:

private:
    BenchFn function;

};

#endif //SIMULATION_PROJECT_BENCHMARKUNIT_H