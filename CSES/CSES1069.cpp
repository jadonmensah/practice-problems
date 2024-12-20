#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    int l = 0, r = 0;
    int m = 0;
    while(r < line.length()) {
        if (line.at(l) == line.at(r)) {
            if (r + 1 - l > m) m = r + 1 - l;
            r++;
        } else {
            l = r;
        }
    }
    cout << m << "\n";
}
