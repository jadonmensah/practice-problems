#include <iostream>
#include <cmath>

int main() {
    std::string input;
    std::getline(std::cin, input);
    int n = std::stoi(input);
    int a = 1;
    unsigned int b = pow(10,9) + 7;
    for (int i = 0; i < n; i++) {
        a = (2 * a) % b;
    }
    std::cout << a;
}
