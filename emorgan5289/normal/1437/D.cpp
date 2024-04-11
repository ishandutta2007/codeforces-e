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
        vector<int> a(n); for (auto& x : a) cin >> x;
        int ans = 1, x = 1, y = 0, r = 0;
        for (int i = 1; i < n; i++) {
            r++;
            if (i == n-1 || a[i+1] < a[i]) {
                debug(x, y, r);
                if (x == 0) swap(x, y), ans++;
                x--;
                y += r;
                r = 0;
            }
        }
        cout << ans << "\n";
    }
}