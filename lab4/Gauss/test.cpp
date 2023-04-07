
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string>

#include <cmath>

#include "Gauss.h"

int main(int argc, char** argv)
{
    int n;
    double** matrix;
    double* f;
    double* x;

    std::istream* abstract_input;
    std::ifstream file;
    std::string trash;

    if (argc > 1)
    {
        std::string file_name(argv[1]);

        std::ios_base::iostate exceptionMask = file.exceptions() | std::ios::failbit;
        file.exceptions(exceptionMask);

        try {
            file.open(file_name);
        }
        catch (std::ios_base::failure& e) {
            std::cout << e.what() << '\n';
            return -1;
        }

        abstract_input = &file;
    }
    else
    {
        abstract_input = &std::cin;
    }

    // ввод данных из файла
    // формат входного файла
    // первая строка: длина матрицы (ширина, длина массива свободных членов)
    // следующие n строк: строки матрицы (в каждой по n чисел)
    // последняя строка: столбец свободных членов (записан в строку)

    *abstract_input >> n;

    matrix = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            *abstract_input >> matrix[i][j];
        }
    }

    f = new double[n];
    for (int i = 0; i < n; i++)
    {
        *abstract_input >> f[i];
    }

    bool is_not_degenarate = LinearSolve(matrix, f, n);

    if (is_not_degenarate)
    {
        std::cout << "Result: " << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout << std::setw(15) << f[i];
        }
        std::cout << std::endl;

        x = new double[n];
        for (int i = 0; i < n; i++)
        {
            *abstract_input >> x[i];
        }

        std::cout << "Right answer: " << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout << std::setw(15) << x[i];
        }
        std::cout << std::endl;

        bool is_right = true;
        for (int i = 0; i < n; i++)
        {
            is_right = is_right && (abs(x[i] - f[i]) < accuracy);
        }

        if (is_right)
        {
            std::cout << "Right" << std::endl;
        }
        else
        {
            std::cout << "Wrong" << std::endl;
        }
    }

    else
    {
        std::cout << "Matrix is degenerate" << std::endl;
    }

    if (argc > 1)
    {
        file.close();
    }

    abstract_input = nullptr;

    return 0;
}