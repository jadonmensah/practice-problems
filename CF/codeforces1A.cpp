//CF 1A
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,m,a;
    cin >> n >> m >> a;
    long long out = ceil((long double)n/(long double)a) * ceil((long double)m/(long double)a);
    cout << out;
    return 0;
}
