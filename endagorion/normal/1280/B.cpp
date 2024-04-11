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
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        forn(i, n) cin >> s[i];
        bool anya = false, alla = true, cor = false;
        vi row(n), col(m);
        forn(i, n) forn(j, m) {
            anya |= s[i][j] == 'A';
            alla &= s[i][j] == 'A';
            row[i] += int(s[i][j] == 'A');
            col[j] += int(s[i][j] == 'A');
            if (min(i, n - i - 1) == 0 && min(j, m - j - 1) == 0) cor |= s[i][j] == 'A';
        }
        bool run = false, side = false, bord = false;
        side = (row[0] == m || row[n - 1] == m || col[0] == n || col[m - 1] == n);
        bord = (row[0] != 0 || row[n - 1] != 0 || col[0] != 0 || col[m - 1] != 0);
        forn(i, n) if (row[i] == m) run = true;
        forn(j, m) if (col[j] == n) run = true;
        int ans;
        if (!anya) ans = -1;
        else if (alla) ans = 0;
        else if (side) ans = 1;
        else if (cor || run) ans = 2;
        else if (bord) ans = 3;
        else ans = 4;
        if (ans == -1) cout << "MORTAL\n";
        else cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}