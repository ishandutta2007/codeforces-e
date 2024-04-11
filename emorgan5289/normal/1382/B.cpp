#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool v = 1, u = 1;
        while (n--) {
            int x; cin >> x;
            if (x == 1 && u) v = !v;
            else u = 0;
        }
        cout << (v^u ? "First" : "Second") << "\n";
    }
}