

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

    std::sort(intervals, intervals + size, [&](Interval& a, Interval& b){return a.first < b.first || a.last < b.last;});

    /*for (int i = 0; i < size; i++)
    {
        std::cout << intervals[i].first << ":" << intervals[i].last << std::endl;
    }*/

    Interval* current = intervals;

    while (current != intervals + size)
    {
        std::cout << current->first << ":" << current->last << std::endl;

        int last = current->last;

        while(current != intervals + size && current->first < last)
        {
            current++;
        }
    }

    return 0;
}