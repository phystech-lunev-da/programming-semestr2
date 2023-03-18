#include <iostream>

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 != 0 && i % 5 != 0)
        {
            std::cout << i << std::endl;
        }
        else{
            if (i % 3 == 0) {
                std::cout << "Fizz";
            }
            if (i % 5 == 0) {
                std::cout << "Buzz";
            }
            std::cout << std::endl;
        }
    }
}