#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

const int maxn = 1100;
int l[maxn], r[maxn];
int a[maxn];

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
    forn(i, n) cin >> l[i];
    forn(i, n) cin >> r[i];
    int given = 0;
    bool ok = true;
    int s = n;
    while (ok && given < n) {
        vi q;
        forn(i, n) {
            if (a[i]) continue;
            if (l[i] < 0 || r[i] < 0) {
                ok = false;
                break;
            }
            if (l[i] > 0 || r[i] > 0) continue;
            a[i] = s;
            q.pb(i);
        }
        if (!ok) break;
        if (q.empty()) {
            ok = false;
            break;
        }
        for (int i: q) {
            ++given;
            forn(j, n) {
                if (a[j]) continue;
                --(j < i ? r[j] : l[j]);
            }
        }
        --s;
    }

    if (!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        forn(i, n) cout << a[i] << ' ' ;
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}