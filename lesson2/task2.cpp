#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

#define MAX_CIRCLE_LENGTH 1024

int sqr_sum_of_digits(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += (num % 10) * (num % 10);
        num /= 10;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    std::map<int, int> found_numbers;
    found_numbers[1] = 1;

    for (int i = 2; i < 1000; i++)
    {
        int next = sqr_sum_of_digits(i);
        std::vector<int> previous(0);

        std::vector<int>::iterator previous_iter = std::find(previous.begin(), previous.end(), next);
        std::map<int, int>::iterator found_numbers_iter = found_numbers.find(next);

        while (previous_iter == previous.end() && found_numbers_iter != found_numbers.end())
        {
            previous.push_back(next);
            next = sqr_sum_of_digits(next);

            previous_iter = std::find(previous.begin(), previous.end(), next);
            found_numbers_iter = found_numbers.find(next);
        }
        if (previous_iter != previous.end())
        {
            found_numbers[next] = 0;
            for (int i = 0; i < previous.size(); i++)
            {
                found_numbers[previous[i]] = 0;
            }
        }
        else if (found_numbers_iter == found_numbers.end())
        {
            found_numbers[i] = found_numbers[next];
        }
    }

    for (int i = 0; i < found_numbers.size(); i++)
    {
        if (found_numbers[i])
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}