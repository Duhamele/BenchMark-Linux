//
// Created by duhamel on 22/01/2026.
//
#include <stdexcept>

#include "histgramme.h"

inline Histogram::Histogram(double start, double end, std::vector<double> hist):start(start),end(end),hist(hist)
{

}

inline size_t Histogram::size() const
{
    return hist.size();
}

inline std::pair<double, double> Histogram::interval(int _case) const
{
    return std::make_pair(start+(end-start)*_case,start+(end-start)*(_case+1));
}

inline double Histogram::value(double point) const
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

inline double Histogram::value(int _case) const
{
    if (_case<0||_case>size()-1)
    {
        throw std::out_of_range("Histogram::value");
    }
    return hist[_case];
}
