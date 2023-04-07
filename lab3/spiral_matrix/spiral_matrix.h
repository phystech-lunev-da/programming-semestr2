
int** spiral_matrix(int length)
{
    int** matrix = new int*[length];

    for (int i = 0; i < length; i++)
    {
        matrix[i] = new int[length];
        for (int j = 0; j < length; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int num = 1;

    for (int i = 0; i < length / 2 + 1; i++)
    {
        for (int j = i; j < length - 1 - i; j++)
        {
            matrix[i][j] = num++;
        }

        for (int j = i; j < length - 1 - i; j++)
        {
            matrix[j][length - 1 - i] = num++;
        }

        for (int j = i; j < length - 1 - i; j++)
        {
            matrix[length - 1 - i][length - j - 1] = num++;
        }

        for (int j = i; j < length - 1 - i; j++)
        {
            matrix[length - j - 1][i] = num++;
        }
    }

    if (length % 2 != 0)
    {
        matrix[length/2][length/2] = num;
    }

    return matrix;
}