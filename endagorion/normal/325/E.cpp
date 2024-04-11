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

const int maxn = 100000;
int c[maxn];
int to[maxn];
int par[maxn];

void dfs(int v, int C) {
    if (c[v] != -1) return;
    c[v] = C;
    dfs(to[v], C);
}

int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    if (n & 1) {
        cout << -1 << '\n';
        return 0;
    }

    forn(i, n / 2) {
        to[i] = 2 * i;
        to[i + n / 2] = 2 * i + 1;
    }

    int C = 0;
    forn(i, n) c[i] = -1;
    forn(i, n) {
        if (c[i] != -1) continue;
        dfs(i, C++);
    }

    forn(i, C) par[i] = i;
    forn(i, n / 2) {
        if (root(c[i]) == root(c[i + n / 2])) continue;
        par[root(c[i])] = root(c[i + n / 2]);
        swap(to[i], to[i + n / 2]);
        --C;
    }
    assert(C == 1);

    int v = 0;
    forn(i, n + 1) {
        cout << v << ' ';
        v = to[v];
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}