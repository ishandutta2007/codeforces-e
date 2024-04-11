#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        string s; cin >> s;
        string t(s.size(), '$');
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') t[i] = 'D';
            if (s[i] == 'D') t[i] = 'U';
        }
        for (int i = 0; i < n; i++) {
            if (t[i] == '$') {
                if (i == 0 || t[i-1] != 'L')
                    t[i] = 'L';
                else t[i] = 'R';
            }
        }
        cout << t << "\n";
    }
}