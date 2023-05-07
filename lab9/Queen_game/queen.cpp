
#include <iostream>
#include <cstdlib>

#include <iomanip>

void display_moves(int** moves, int m, int n)
{
    std::cout << std::endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::setw(3) << moves[i][j];
        }
        std::cout << std::endl;
    }
}

bool is_any_win_pos(int i, int j, int** moves, int m, int n)
{
    bool result = false;
    for (int k = n - 1; k >= j; k--)
    {
        result = result || (moves[i][k] == -1);
    }

    for (int k = m - 1; k >= i; k--)
    {
        result = result || (moves[k][j] == -1);
    }

    for (int k = std::min(m - 1 - i, n - 1 - j); k >= 0; k--)
    {
        result = result || (moves[i + k][j + k] == -1);
    }

    return result;
}

int main()
{
    int m, n;

    std::cin >> m >> n;

    int** moves = new int*[m];

    for (int i = 0; i < m; i++)
    {
        moves[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            moves[i][j] = 0;
        }
    }

    moves[m-1][n-1] = -1;

    //display_moves(moves, m, n);

    for (int step = 1; step < std::min(m, n); step++)
    {
        for (int i = 0; i <= step; i++)
        {
            if (is_any_win_pos(m - 1 - step + i, n - 1 - step, moves, m, n))
            {
                moves[m - 1 - step + i][n - 1 - step] = 1;
            }
            else
            {
                moves[m - 1 - step + i][n - 1 - step] = -1;
            }
        }
        for (int i = 0; i <= step; i++)
        {
            if (is_any_win_pos(m - 1 - step, n - 1 - step + i, moves, m, n))
            {
                moves[m - 1 - step][n - 1 - step + i] = 1;
            }
            else
            {
                moves[m - 1 - step][n - 1 - step + i] = -1;
            }
        }

        //display_moves(moves, m, n);
    }

    if (m > n)
    {
        for (int i = m - n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (is_any_win_pos(i, j, moves, m, n))
                {
                    moves[i][j] = 1;
                }
                else
                {
                    moves[i][j] = -1;
                }
                //display_moves(moves, m, n);
            }
        }
    }


    else
    {
        for (int j = n - m - 1; j >= 0; j--)
        {
            for (int i = m - 1; i>=0; i--)
            {
                if (is_any_win_pos(i, j, moves, m, n))
                {
                    moves[i][j] = 1;
                }
                else
                {
                    moves[i][j] = -1;
                }
                //display_moves(moves, m, n);
            }
        }
    }

    display_moves(moves, m, n);

    for (int i = 0; i < m; i++)
    {
        delete[] moves[i];
    }
    delete[] moves;

    return 0;
}