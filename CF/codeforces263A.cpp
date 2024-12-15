#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    pair<int, int> coords;
    for (int i = 0; i < 5; i++) {
        getline(cin, line);
        stringstream ss(line);
        bool break_outer = false;
        string val_str;
        for (int j = 0; j < 5; j++) {
            ss >> val_str;
            if (stoi(val_str) == 1) {
                coords = {i, j};
                // break_outer = true;
                break;
            }
        }
        // if (break_outer) break;
    }
    int min_moves = abs(coords.first + 1 - 3) + abs(coords.second + 1 - 3);
    cout << min_moves << "\n";
    return 0;
}
