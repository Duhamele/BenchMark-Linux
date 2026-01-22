//
// Created by duhamel on 22/01/2026.
//

#ifndef BENCHMARK_LINUX_HISTGRAMME_H
#define BENCHMARK_LINUX_HISTGRAMME_H
#include <vector>
struct Histogram
{


    Histogram(double start, double end, std::vector<double> hist);
    size_t size() const;
    std::pair<double,double> interval(int _case)const;
    double value(double point) const;
    double value(int _case) const;




private:
    double start;
    double end;
    std::vector<double> hist;
};


#endif //BENCHMARK_LINUX_HISTGRAMME_H
