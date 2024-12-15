//AoC Day 2 part 1
#include <bits/stdc++.h>
using namespace std;

vector<int> my_split(string line) {
    stringstream stream(line);
    string level;
    vector<int>  res;
    while (stream >> level) {
        res.push_back(stoi(level));
    }
    return res;
}

int main() {
    ifstream input("input2.txt");
    int counter = 0;
    string line;
    while (getline(input, line)) {
        bool safe = true;
        int prev_direction = 0; // -1 : decreasing, 0 : unknown, 1 : increasing
        vector<int> report = my_split(line);
        for (int i = 1; i < report.size(); i++) {
            int diff = report[i] - report[i-1];
            if (diff > 3) safe = false;
            if (diff < -3) safe = false;
            if (diff == 0) safe = false;
            int direction;
            if (diff > 0) direction = 1;
            if (diff < 0) direction = -1;
            if ((i > 1) && (direction != prev_direction)) {
                safe = false;
            }
            prev_direction = direction;
        }
        if (safe) counter++;
    }
    cout << counter << "\n";
    return 0;
}
