//
// Created by duhamel on 22/01/2026.
//
#include "MeasureTimer.h"

#include <algorithm>
#include <limits.h>


void MeasureTimerBase::sort()
{
    if (!_sort)
    {
        std::ranges::sort(values);
    }
}

long double MeasureTimerBase::average()
{
    long double sum=0.0;
    for (long long int i=0;i<values.size();i++)
        sum+=values[i];
    return sum/values.size();
}

long long int MeasureTimerBase::min()
{
    if (values.empty())
    {
        return -1;
    }
    else if (_sort)
    {
        return values[0];
    }
    else
    {
        long long int min=LONG_LONG_MAX;
        for (long long int i=0;i<values.size();i++)
        {
            if (values[i]<min)
            {
                min=values[i];
            }
        }
        return min;
    }

}

long long int MeasureTimerBase::median()
{
    if (values.empty())
    {
        return -1;
    }
    sort();
    if (values.size()%2==0)
    {
        return (values[values.size()/2]+values[(values.size()/2)+1])/2;
    }else
    {
        return values[values.size()/2];
    }
}

long double MeasureTimerBase::variance()
{
    if (values.empty())
    {
        return -1;
    }
    else
    {
        long double sum=0.0;
        long double average=this->average();
        for (long long int i=0;i<values.size();i++)
        {
            sum+=(values[i]-average)*(values[i]-average);

        }
        return sum/values.size();
    }
}

Histogram MeasureTimerBase::histogram()
{
    sort();
    double lenght=max()-min();
    double star= std::min(min()-0.005*lenght,0.);
    double end=max()+0.005*lenght;
    std::vector<int> hist;
    hist.resize(10);
    long long int step=(end-star)/10 +star;
    int count=0;
    for (auto val:values)
    {
        if (val> step)
        {
            count++;
            step+=(end-star)/10;
        }
        hist[count]++;
    }
    std::vector<double> vals(hist.begin(),hist.end());
    return Histogram(star,end,vals);




}

long long int MeasureTimerBase::max()
{
    if (values.empty())
    {
        return -1;
    }else if (_sort)
    {
        return values.back();
    }
    else
    {
        long long int max=0;
        for (long long int i=0;i<values.size();i++)
        {
            if (values[i]>max)
            {
                max=values[i];
            }
        }
        return max;
    }
}
