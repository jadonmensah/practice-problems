#include <bits/stdc++.h>
using namespace std;
int main() {
    int coords[3] = {0};
    string line;
    bool f = false; // discard first line, we don't care
    int n = 1;
    int c = 0;
    while (c < n) {
        getline(cin, line);
        stringstream ss(line);
        if (!f) {
            f = true;
            string num;
            ss>>num;
            n = stoi(num);
            continue;
        }
        for (int i = 0; i < 3; i++) {
            string num_s;
            ss >> num_s;
            coords[i] += stoi(num_s);
        }
        c++;
    }
    for (auto const& coord: coords) {
        if (coord != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
