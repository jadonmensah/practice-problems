// CSES 1070

#include <iostream>

int main () {
    std::string input;
    std::getline(std::cin, input);
    int n = std::stoi(input);
    // special cases n \elem [1, 4]
    if (n == 1) {
      std::cout << 1;
      return 0;
    } else if (1 < n && n < 4) {
        std::cout << "NO SOLUTION";
        return 0;
    } else if (n == 4) {
        std::cout << "3 1 4 2";
    } else { // greedy cases
        for (int i = n; i > 0; i -= 2) {
            std::cout << i << " ";
        }
        for (int i = n-1; i > 2; i -= 2) {
            std::cout << i << " ";
        }
        std::cout << 1 + (n % 2);
    }
    return 0;
}
