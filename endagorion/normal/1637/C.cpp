#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi64 a(n);
        for (auto &x: a) cin >> x;
        i64 ans = 0;
        for1(i, n - 2) ans += (a[i] + 1) / 2;

        bool ok;
        if (n == 3) ok = a[1] % 2 == 0;
        else {
            ok = false;
            for1(i, n - 2) if (a[i] > 0 && a[i] % 2 == 0) ok = true;
            if (!ok) {
                int mx = *max_element(1 + all(a) - 1);
                if (mx == 0 || mx > 3) ok = true;
                else if (mx == 1) ok = false;
                else {
                    int cp = n - 2 - count(1 + all(a) - 1, 0);
                    ok = cp > 1;
                }
            }
        }
        cout << (ok ? ans : -1LL) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}