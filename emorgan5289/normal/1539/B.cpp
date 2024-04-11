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
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    vector<ll> p(n+1, 0);
    for (int i = 0; i < n; i++)
        p[i+1] = p[i]+(s[i]-'a'+1);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << p[r]-p[l-1] << "\n";
    }
}