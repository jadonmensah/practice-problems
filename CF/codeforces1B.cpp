// CF 1B
// TODO fix bugs, ensure rows/columns swapped correctly
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isRxCy(string input) {
    return input.substr(0,1) == "R" && isdigit((char)input.at(1)) && input.substr(2).find("C") != string::npos;
}

pair<ll, ll> getRxCy(string input) {
    ll x = std::stoi(input.substr(1, input.find("C")- 1));
    ll y = std::stoi(input.substr(input.find("C")+1));
    return make_pair(x, y);
}

pair<ll, ll> getABnum(string input) {
    ll x;
    int idx = min({input.find("1"),
                   input.find("2"),
                   input.find("3"),
                   input.find("4"),
                   input.find("5"),
                   input.find("6"),
                   input.find("7"),
                   input.find("8"),
                   input.find("9"),
                  });
    for (int i = idx-1; i >= 0 ; i--) {
        x += ((int)input.at(i) - 64)*pow(26, idx - i + 1); // "A" = 65
    }
    ll y = std::stoi(input.substr(idx));
    return make_pair(x, y);
}
// AAA = 26^2 + 26^1 + 26^0
string toABnum(pair<ll, ll> coord) {
    string res;
    ll x = coord.first;
    ll y = coord.second;
    while (x > 0) {
        res.insert(0,1, (x % 26)+64);
        x = (x - (x % 26)) / 26;
    }
    res += to_string(y);
    return res;
}

string toRxCy(pair<ll,ll> coord) {
    return "R" + to_string(coord.first) + "C" + to_string(coord.second);
}

int main() {
    string bin;
    cin >> bin;
    bin.clear();
    string input;
    pair<ll, ll> coord;
    while (cin >> input) {
        if (isRxCy(input)) {
            coord = getRxCy(input);
            cout << toABnum(coord);
        } else {
            coord = getABnum(input);
            cout << toRxCy(coord);
        }
    }
}
