
#include <iostream>
#include <cstdlib>

int collats_move_count(int num, int prev_moves)
{
    if (num == 1) return prev_moves;

    int next_num;
    if (num % 2) next_num = 3 * num + 1;
    else next_num = num / 2;

    return collats_move_count(next_num, prev_moves + 1);
}

int main(int argc, char* argv[])
{
    int number;
    std::cout << "Input the number: " << std::endl;
    std::cin >> number;

    std::cout << "Count moves: " << collats_move_count(number, 0);
    return 0;
}