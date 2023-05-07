
#include <iostream>
#include <cstdlib>

int main()
{
    int n;
    std::cin >> n;

    int* cell = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> cell[i];
    }

    int* ways = new int[n];

    ways[0] = 1;
    ways[1] = cell[1] * ways[0];
    ways[2] = cell[2] * (ways[1] + ways[0]);

    for (int i = 3; i < n; i++)
    {
        ways[i] = cell[i] * (ways[i-1] + ways[i-2] + ways[i-3]);
    }

    std::cout << "array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << ways[i] << " ";
    }
    std::cout << std::endl;

    std::cout << ways[n-1] << std::endl;

    return 0;
}