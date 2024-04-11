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

    int n;
    cin >> n;
    vi64 a(n);
    forn(i, n) cin >> a[i];
    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        cout << -a[0] << '\n';
        forn(i, 2) {
            cout << 1 << ' ' << 1 << '\n';
            cout << 0 << '\n';
        }
    } else {
        cout << 1 << ' ' << n - 1 << '\n';
        forn(i, n - 1) {
            i64 x = a[i] % n;
            if (x < 0) x += n;
            x *= (n - 1);
            cout << x << ' ';
            a[i] += x;
        }
        cout << '\n';
        cout << n << ' ' << n << '\n';
        cout << -a[n - 1] << '\n';
        a[n - 1] = 0;
        cout << 1 << ' ' << n << '\n';
        forn(i, n) {
            assert(a[i] % n == 0);
            cout << -a[i] << ' ';
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}