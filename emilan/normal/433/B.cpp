#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
    freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

int main() {
    ioThings();

    int n; cin >> n;
    vector<ll> v(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    s = v;
    sort(all(s));
    partial_sum(all(v), v.begin());
    partial_sum(all(s), s.begin());

    int m; cin >> m;
    while (m--) {
        int t, l, r; cin >> t >> l >> r;
        r--, l -= 2;
        if (t == 1)
            cout << v[r] - (l == -1 ? 0 : v[l]);
        else
            cout << s[r] - (l == -1 ? 0 : s[l]);
        cout << '\n';
    }

    return 0;
}