
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

#include "Gauss.h"

int main(int argc, const char** argv)
{
    int n;
    double** matrix;
    double* f;

    if (argc > 1)
    {
        const char* file_name = argv[1];
    
        std::ifstream file;

        std::ios_base::iostate exceptionMask = file.exceptions() | std::ios::failbit;
        file.exceptions(exceptionMask);

        try {
            file.open(file_name);
        }
        catch (std::ios_base::failure& e) {
            std::cout << e.what() << '\n';
            return -1;
        }

        file >> n;

        matrix = new double*[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                file >> matrix[i][j];
            }
        }

        f = new double[n];
        for (int i = 0; i < n; i++)
        {
            file >> f[i];
        }
    }
    else
    {
        std::cin >> n;

        matrix = new double*[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

        f = new double[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> f[i];
        }
    }

    // ввод данных из файла
    // формат входного файла
    // первая строка: длина матрицы (ширина, длина массива свободных членов)
    // следующие n строк: строки матрицы (в каждой по n чисел)
    // последняя строка: столбец свободных членов (записан в строку)

    bool is_not_degenarate = LinearSolve(matrix, f, n);

    if (is_not_degenarate)
    {
        std::cout << "Result: " << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout << std::setw(7) << f[i];
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Matrix is degenerate" << std::endl;
    }

    return 0;
}