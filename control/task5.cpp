
#include <iostream>
#include <algorithm>

int main()
{
    unsigned int N;

    std::cin >> N;

    unsigned int* a = new unsigned int[N];

    for (unsigned i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }

    int K;

    std::cin >> K;

    std::sort(a, a + N);

    unsigned int curr_index = 0;

    for (unsigned int i = 0; i < N; i++)
    {
        if (a[curr_index] != a[i])
        {
            int diff = a[i] - a[curr_index];

            K -= diff * (i);
            
            if (K < 0)
            {
                std::cout << a[N-1];
                delete[] a;
                return 0;
            }

            curr_index = i;
        }
    }

    std::cout << a[N - 1] + K / N + K % N << std::endl;

    delete[] a;

    return 0;
}