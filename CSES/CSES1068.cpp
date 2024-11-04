// CSES 1068 - Weird Algorithm

#include<iostream>
#include <vector>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    unsigned long long int n = std::stoi(input);
    std::cout << n;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        std::cout << " " << n;
    }
    std::cout << std::endl;
}
