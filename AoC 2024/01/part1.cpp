// AoC Day 1, part 1 - jadon mensah
#include <bits/stdc++.h>
using namespace std;

vector<int> parse_line(string line) {
    vector<int> res;
    res.push_back(stoi(line.substr(0,5)));
    res.push_back(stoi(line.substr(8, 5)));
    return res;
}

int main() {
    ifstream in("input.txt");
    string line;
    int counter = 0;
    long long res = 0;
    multiset<int> left;
    multiset<int> right;
    while (getline(in, line)) {
        vector<int> split = parse_line(line);
        left.insert(split[0]);
        right.insert(split[1]);
        counter++;
    }
    for (int i = 0; i < counter; i++) {
        res += abs(*left.begin() - *right.begin());
        left.erase(left.begin());
        right.erase(right.begin());
    }
    cout << res << "\n";
    return 0;
}
