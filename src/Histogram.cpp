//
// Created by duhamel on 22/01/2026.
//
#include <numeric>
#include <stdexcept>

#include "Histogram.h"

Histogram::Histogram(double start, double end, std::vector<double> hist):start(start),end(end),hist(hist)
{
    for (auto element : hist)
    {
        if (element<0)
        {
            throw std::out_of_range("Histogram::Histogram");
        }

    }

}

inline size_t Histogram::size() const
{
    return hist.size();
}

std::pair<double, double> Histogram::interval(int _case) const
{
    return std::make_pair(start+(end-start)*_case,start+(end-start)*(_case+1));
}

double Histogram::value(double point) const
{
    if (point<start || point>end)
    {
        throw std::out_of_range("Histogram::value");
    }
    auto point_ref=point-start;
    double length=end-start;
    int _case=point_ref/length*static_cast<double>(hist.size());
    if (_case<0)
    {
        return hist[0];
    }
    if (_case>=static_cast<int>(hist.size()))
    {
        return hist.back();
    }
    auto __case=this->interval(_case);
    if (point<__case.first)
    {
        return hist[_case-1];
    }
    if (point<=__case.second)
    {
        return hist[_case];
    }
    return hist[_case+1];

}

double Histogram::value(int _case) const
{
    if (_case<0||_case>size()-1)
    {
        throw std::out_of_range("Histogram::value");
    }
    return hist[_case];
}

double Histogram::average() const

{
    double sum=0;
    double coff=0;
    for (int i=0;i<size();i++)
    {
        coff+=hist[i];
        sum+=hist[i]*(interval(i).first+interval(i).second)/2;
    }
    return sum/coff;
}

double Histogram::median() const
{
    double med=std::accumulate(hist.begin(),hist.end(),0.0)/2;
    double sum=0;
    for (int i=0;i<size();i++)
    {
        sum+=hist[i];
        if (sum>med)
        {
            auto interval=this->interval(i);
            auto lenght_interval=interval.second-interval.first;
            auto lenght=sum-med;
            return interval.second-(lenght/hist[i])*lenght_interval;

        }
        if (sum==med)
        {
            return this->interval(i).second;
        }
    }
    return end;
}
