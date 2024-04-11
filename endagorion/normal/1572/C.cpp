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

vi a;
const int maxn = 3100;
vi lst[maxn];

int dp[maxn][maxn];

int get_dp(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] >= 0) return dp[l][r];
    int &res = dp[l][r];
    uax(res, get_dp(l + 1, r));
    for (int p: lst[a[l]]) {
        if (p > l && p < r) uax(res, get_dp(l + 1, p) + get_dp(p, r) + 1);
    }
    return res;
}

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
        forn(i, n) lst[i].clear();
        a.clear();
        forn(i, n) {
            int x;
            cin >> x;
            --x;
            if (!a.empty() && a.back() == x) continue;
            lst[x].pb(a.size());
            a.pb(x);
        }
        n = a.size();
        forn(l, n + 1) forn(r, n + 1) dp[l][r] = -1e9;
        cout << n - 1 - get_dp(0, n) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}