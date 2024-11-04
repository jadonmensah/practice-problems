// CSES 1754
// even a:
// a = 2*n = 2*(n-1) + 2(1) = 2*(n-2) + 4(1) etc.
// b = n, b = (n-1) + 2(2), b = (n-2) + 4*2 ... b=2n
// for even a = 2n, b = (n-k) + 2k(2) where k in [0,n] intersect Z
// b = 3k + n
// odd a:
// a = 2m+1
// b = (m-k) + (2k+1)(2) where k in [0, m] intersect Z
// b = 3k + m + 2

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
int main() {
    bool res;
    int n;
    std::string input;
    std::getline(std::cin, input);
    long long a, b;
    while (std::getline(std::cin, input)) {
        std::stringstream ss(input);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> ab(begin, end);
        a = std::stoi(ab[0]);
        b = std::stoi(ab[1]);
        if (!a) {
            res = (a != b);
        }
        if (a % 2) {
            n = (a-1)/2; // 5
            res = abs((b - (n+2))) % 3;
        } else {
            n = a/2;
            res = abs((b - n)) % 3;
        }
        if (a > 2 * b || a < 0.5*b) {
            res = true;
        }
        if (!res) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
