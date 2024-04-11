#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, k;
        cin >> n >> k;
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        int seg = max(r1, r2) - l1;
        int emp = max(0, l2 - r1);
        int fil = emp ? seg : 2 * seg - (r2 - l2 + r1 - l1);
        k = max(0ll, k - (ll)(seg - fil) * n);

        int step = 0;
        while (k) {
            int tar = min(k, fil);
            if ((!step && emp) || (n && emp + tar < 2 * tar)) {
                step += emp + tar;
                k -= tar;
                n--;
            } else {
                step += 2 * k;
                k = 0;
            }
        }

        cout << step << '\n';
    }

    return 0;
}