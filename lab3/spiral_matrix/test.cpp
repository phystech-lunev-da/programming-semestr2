
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "spiral_matrix.h"

int main()
{
    int length;

    std::cin >> length;

    int** matrix = spiral_matrix(length);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }  

    delete[] matrix;

    return 0;
}