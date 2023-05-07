#include <iostream>
#include <cstdlib>

int main()
{
    int n, m;

    std::cin >> m >> n;

    int** board = new int*[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new int [m];
        for (int j = 0; j < m; j++)
        {
            std::cin >> board[i][j];
        }
    }

    int A;
    std::cin >> A;
    
    

    int** optim = new int*[n];

    for (int i = 0; i < n; i++)
    {
        optim[i] = new int[i];
        for (int j = 0; j < n; j++)
        {
            optim[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        optim[i][0] = board[i][0];
    }

    for (int j = 0; j < m; j++)
    {
        optim[0][j] = board[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            optim[i][j] = board[i][j] + std::max(optim[i-1][j], optim[i][j-1]);
            board[i][j] = 0;
        }
    }



    std::cout << optim[n-1][m-1];

    for (int i = n; i >= 0; i--)
    {
        delete[] board[i];
    }
    delete[] board;

     for (int i = n; i >= 0; i--)
    {
        delete[] optim[i];
    }
    delete[] optim;

    return 0;
}