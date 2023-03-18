
#include <iostream>
#include <cstdlib>

bool is_prime(int num)
{
    if (num == 1) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int count_prime(int* array, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        count += is_prime(*(array + i));
    }
    return count;
}

int main(int argc, char* argv[])
{
    int length;

    std::cout << "Input number of elements: ";
    std::cin >> length;
    std::cout << std::endl;

    int* array = new int[length];

    std::cout << "Input elements of array: " << std::endl;
    for (int i = 0; i < length; i++)
    {
        std::cout << i << ": ";
        std::cin >> array[i];
        std::cout << std::endl;
    }

    /*int array[10];

    for (int i = 0; i < 10; i++) {
        array[i] = rand() % (100 + 1 + 1) + 1;
    }

    array[0] = 1;

    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << '\t';
    }
    std::cout << std::endl;*/

    std::cout << "Prime count: " << count_prime(array, length);

    return 0;
}