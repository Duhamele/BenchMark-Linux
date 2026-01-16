//
// Created by duhamel on 16/01/2026.
//

#ifndef SIMULATION_PROJECT_BENCHMARKUNIT_H
#define SIMULATION_PROJECT_BENCHMARKUNIT_H


#include "BrenchMark.h"
template<typename T>
class BenchMarkTestUnitaire:BenchMarkTest
{


    public:
    using BenchFn = T(*)();
    BenchMarkTestUnitaire(std::string name,int line,std::string file,BenchFn
    function):BenchMarkTest(name,line,file),function(function)
    {}
private:
    BenchFn function;

};

#endif //SIMULATION_PROJECT_BENCHMARKUNIT_H