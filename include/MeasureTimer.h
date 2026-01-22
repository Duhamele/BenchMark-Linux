//
// Created by duhamel on 20/01/2026.
//

#ifndef BENCHMARK_LINUX_MEASURETIMER_H
#define BENCHMARK_LINUX_MEASURETIMER_H
#include <vector>

class MeasureTimerBase
{
protected:
    std::vector<long long int> values;
    bool sort = false;

public:
    long double average();
    long long int min();
    long long int max();
    long long int median();
    long double variance();
};


#endif //BENCHMARK_LINUX_MEASURETIMER_H
