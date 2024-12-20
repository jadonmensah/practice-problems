
#include <bits/stdc++.h>
using namespace std;
int main() {
    string inf;
    getline(cin, inf);
    stringstream ss(inf);
    int n;
    ss >> n;
    int target;
    ss>>target;
    string line;
    getline(cin, line);
    stringstream s2(line);
    unordered_map<int, vector<int>> m; // Regular map is O(log(n)) insertion (bad!)
    vector<int> q;
    for(int i = 0; i < n; i++) {
        int curr;
        s2 >> curr;
        if (curr >= target) continue; // Not strictly necessary but TLEs otherwise
        if (m.count(curr)) {
            m[curr].push_back(i);
            q.push_back(curr);
            continue;
        }
        m.insert({curr, {i}});
        q.push_back(curr);
    }
    bool found = false;
    for (auto const& [num, idxs]: m) {
        int idx = idxs[0];
        if (m.count(target-num)) {
            for (int& j: m[target-num]) { // Looks bad, but actually will do at most 2 iterations
                if (j != idx) {
                    cout << ++idx << " " << ++j << "\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }
    if (found) return 0;
    cout << "IMPOSSIBLE\n";
    return 0;
}
