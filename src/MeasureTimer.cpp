//
// Created by duhamel on 22/01/2026.
//
#include "MeasureTimer.h"

#include <algorithm>
#include <limits.h>


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
    else if (sort)
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
    if (!sort)
    {
        std::sort(values.begin(),values.end());
    }
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

long long int MeasureTimerBase::max()
{
    if (values.empty())
    {
        return -1;
    }else if (sort)
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
