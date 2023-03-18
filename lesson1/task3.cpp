#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    const int array_size = 10;

    int array[array_size];

    /*for (int i = 0; i < array_size; i++)
    {
        std::cout << "Input the number " << i << ": ";
        std::cin >> array[i];
        std::cout << std::endl;
    }*/

    std::srand(std::time(NULL));

    for (int i = 0; i < array_size; i++)
    {
        array[i] = std::rand() % 10;
    }

    std::cout << "Array: " << std::endl;
    for (int i = 0; i < array_size; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;

    int max1 = array[0], max2 = array[0];

    for (int i = 0; i < array_size; i++)
    {
        if (max1 < array[i]) {
            max2 = max1;
            max1 = array[i];
        } else if (max2 < array[i]) {
            max2 = array[i];
        }
    }

    std::cout << "the second max: " << max2 << std::endl;

    return 0;
}