#pragma once

#include <iostream>

struct thing
{
    int p;
    int w;
};

float p_m(thing& t)
{
    return (float)t.p / (float)t.w;
}

bool is_optim(thing& t1, thing& t2)
{
    return (p_m(t1)) > (p_m(t2));
}

void display(thing& t)
{
    std::cout << "{ p: " <<  t.p << ", w: " << t.w << ", p/w: " << p_m(t) << " }" << std::endl;
}

void display(int n, thing* t)
{
    for (int i = 0; i < n; i++)
    {
        display(t[i]);
    }
}
