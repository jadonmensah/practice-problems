//AoC Day 2 part 2
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
    ifstream input("test.txt");
    int counter = 0;
    string line;
    while (getline(input, line)) {
        int count_unsafe = 0;
        int prev_direction = 0; // -1 : decreasing, 0 : unknown, 1 : increasing
        vector<int> report = my_split(line);
        for (int i = 1; i < report.size(); i++) {
            int diff = report[i] - report[i-1];
            if (diff > 3) {
                count_unsafe++;
                continue;
            }
            if (diff < -3) {
                count_unsafe++;
                continue;
            }
            if (diff == 0){
                count_unsafe++;
                continue;
            }
            int direction;
            if (diff > 0) direction = 1;
            if (diff < 0) direction = -1;
            if ((i > 1) && (direction != prev_direction)) {
                count_unsafe++;
            }
            prev_direction = direction;
        }
        if (count_unsafe < 2) counter++;
    }
    cout << counter << "\n";
    return 0;
}
