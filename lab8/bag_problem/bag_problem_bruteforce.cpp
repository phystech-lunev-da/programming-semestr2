#include <iostream>
#include <algorithm>
#include "thing.h"

int optimize_bag(int, int, thing*, std::vector<thing>*, int, int);

int main()
{
    int n, maxW;
    std::cin >> n >> maxW;

    thing* things = new thing[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> things[i].p >> things[i].w;
    }

    std::vector<thing>* fitted = new std::vector<thing>();

    optimize_bag(n, maxW, things, fitted, 0, 0);

    display(n, things);

    delete[] things;

    return 0;    
}

int optimize_bag(int n, int maxW, thing* things, std::vector<thing>* fitted, int total_p, int total_w)
{
    if (n == 0)
    {
        return total_p;
    }

    int without = optimize_bag(n - 1, maxW, things + 1, fitted, total_p, total_w);
    int with = 0;

    std::vector<thing>* pushed = new std::vector<thing>(*fitted);
    pushed->push_back(things[0]);

    if (total_w + things[0].w <= maxW)
    {
        with = optimize_bag(n - 1, maxW, things + 1, pushed, total_p + things[0].p, total_w + things[0].w);
    }

    if (with > without)
    {
        if (fitted != nullptr)
        {
            delete fitted;
        }
        fitted = pushed;
        return with;
    }
    else
    {
        delete pushed;
        return without;
    }

}