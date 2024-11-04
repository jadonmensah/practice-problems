#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
int main() {
    std::string bin;
    std::getline(std::cin, bin);
    bin.clear();
    std::vector<long long int> xdiff;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> xstrings(begin, end);
    int maxsofar = std::stoi(xstrings[0]);
    for (int i=0; i<xstrings.size(); i++) {
        if (std::stoi(xstrings[i]) <= maxsofar) {
            xdiff.push_back(maxsofar - std::stoi(xstrings[i]));
        } else {
            maxsofar = std::stoi(xstrings[i]);
            xdiff.push_back(0);
        }
    }
    long long int llz = 0;
    std::cout << std::accumulate(xdiff.begin(), xdiff.end(), llz);
}
