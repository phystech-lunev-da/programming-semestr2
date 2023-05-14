#pragma once

#include <iostream>

struct thing
{
    int p;
    int w;
};

bool is_optim(thing& t1, thing& t2)
{
    return t1.p / t1.w < t2.p / t2.w;
}

void display(thing& t)
{
    std::cout << "{ p: " <<  t.p << ", w: " << t.w << " }" << std::endl;
}

void display(int n, thing* t)
{
    for (int i = 0; i < n; i++)
    {
        display(t[i]);
    }
}
