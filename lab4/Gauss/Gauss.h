
#include <cmath>

double accuracy = pow(10, -6);

bool LinearSolve(double** matrix, double* f, unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        if (abs(matrix[i][i]) <= accuracy)
        {
            // ищем элемент с ненулевым элементом
            for (int j = i + 1; j < n; j++)
            {
                if (abs(matrix[j][i]) >= accuracy)
                {
                    // ЭПС: перестановка строк
                    std::swap(f[i], f[j]);
                    for (int k = n - 1; k >= 0; k--)
                    {
                        std::swap(matrix[i][k], matrix[j][k]);
                    }
                }
            }
        }

        double a = matrix[i][i];

        if (a == 0)
        {
            return false;
        }

        // ЭПС: разделить на первый не нулевой элемент
        for (int j = i; j < n; j++)
        {
            matrix[i][j] /= a;
        }
        f[i] /= a;

        for (int j = i + 1; j < n; j++)
        {

            f[j] -= f[i] * matrix[j][i];
            // ЭПС: вычесть, умножив на matrix[j][i]
            for (int k = n - 1; k >= i; k--)
            {
                matrix[j][k] -= matrix[i][k] * matrix[j][i];
            }
        }
    }


    // на этом шаге матрица имеет упрощенный вид
    // далее приводим к треугольному

    for (int i = n - 1; i >= 1; i--)
    {
        for (int k = i - 1; k >= 0; k--)
        {
            f[k] -= f[i] * matrix[k][i];
            matrix[k][i] -= matrix[i][i] * matrix[k][i];
        }
    }

    return true;
}