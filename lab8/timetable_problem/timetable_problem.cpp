

#include <iostream>
#include <algorithm>

struct Interval
{
    int first;
    int last;
};

int main()
{
    int size;
    std::cin >> size;

    Interval* intervals = new Interval[size];

    for (int i = 0; i < size; i++)
    {
        std::cin >> intervals[i].first >> intervals[i].last;
    } 

    std::sort(intervals, intervals + size, [&](Interval a, Interval b){a.first < b.first && a.last < b.last;});


}