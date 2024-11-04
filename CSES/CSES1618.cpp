#include <iostream>
#include <cmath>

int main() {
    std::string input;
    std::getline(std::cin, input);
    int n = std::stoi(input);
    int r = 0;
    for (int i = 1; i<=13; i++) { // 5^13 > 10^9
            r += floor((double)n / (double)(pow(5,i))) ;
    }
    std::cout << r;
    return 0;
}
