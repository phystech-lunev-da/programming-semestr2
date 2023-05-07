
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

void display_matrix(int** matrix, std::string a, std::string b)
{
    std::cout << std::endl;

    a.insert(a.begin(), '*');
    b.insert(b.begin(), '*');

    std::cout << std::setw(3) << " ";

    for (int i = 0; i < b.size(); i++)
    {
        std::cout << std::setw(3) << b[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << std::setw(3) << a[i];
        for (int j = 0; j < b.size(); j++)
        {
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::string str1, str2;

    std::getline(std::cin, str1);
    std::getline(std::cin, str2);

    int length1 = str1.size();
    int length2 = str2.size();

    int** matrix = new int*[length1 + 1];
    
    for(int i = 0; i < length1 + 1; i++)
    {
        matrix[i] = new int[length2 + 1];
        for (int j = 0; j < length2 + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < length1 + 1; i++)
    {
        matrix[i][0] = i;
    }

    for (int i = 0; i < length1 + 1; i++)
    {
        matrix[0][i] = i;
    }

    for (int i = 1; i < length1 + 1; i++)
    {
        for (int j = 1; j < length2 + 1; j++)
        {
            matrix[i][j] = std::min(
                std::min(matrix[i-1][j] + 1,
                    matrix[i][j-1] + 1),
                matrix[i-1][j-1] + 1 - (int)(str1[i-1] == str2[j-1])
            );
        }
    }

    display_matrix(matrix, str1, str2);

    std::cout << matrix[length1][length2] << std::endl;

    return 0;
}