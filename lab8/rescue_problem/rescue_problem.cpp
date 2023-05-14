
#include <iostream>
#include <algorithm>

int main()
{
    int N, limit;
    std::cin >> N;

    int* m = new int[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> m[i];
    }

    std::cin >> limit;

    std::sort(m, m + N);

    int left = 0;
    int right = N-1;

    int count = 0;

    while (left < right)
    {
        if (m[right]>=limit)
        {
            right--;
            count++;
        }
        else if (m[left] + m[right] <= limit)
        {
            count++;
            left++;
            right--;
        }
        else
        {
            right--;
            count++;
        }
    }
    if (left == right)
    {
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}