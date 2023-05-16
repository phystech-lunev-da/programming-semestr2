
#include <iostream>
#include <algorithm>

#include "thing.h"

int main()
{
    int n, maxW;

    std::cin >> n >> maxW;

    thing* things = new thing[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> things[i].p;
        std::cin >> things[i].w;
    }
    std::cout << std::endl;

    std::sort(things, things + n, is_optim);

    display(n, things);

    int current_weight = 0;

    int count = 0;

    while (current_weight + things[count].w <= maxW)
    {
        current_weight += things[count++].w;
    }

    thing* fitted = new thing[count];

    for(int i = 0; i < count; i++)
    {
        fitted[i] = things[i];
    }

    std::cout << std::endl;
    display(count, fitted);

    return 0;
}