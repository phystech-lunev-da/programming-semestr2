
#include <iostream>
#include <cstdlib>


long long akkerman(long long m, long long n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return akkerman(m - 1, 1);
    }
    return akkerman(m - 1, akkerman(m, n - 1));
}

int main(int argc, char* argv[])
{
    long long m, n;
    std::cout << "input m, n" << std::endl;
    std::cin >> m;
    std::cin >> n;

    std::cout << "A(" << m << ", " << n << ") = " << akkerman(m, n) << std::endl;
}