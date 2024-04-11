#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int Mod = 1000000009;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 105;

int n, u, v;
int a[MAXN];

void solve() {
    cin >> n >> u >> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 2e9 + 2;
    for (int i = 0; i < n; i++) {
        if (i + 1 != n) {
            if (a[i + 1] != a[i]) {
                chkmin(ans, u);
            } else {
                chkmin(ans, u + v);
                chkmin(ans, 2 * v);
            }
            if (min(a[i], a[i + 1]) + 2 <= max(a[i], a[i + 1])) {
                chkmin(ans, 0);
            }
            if (abs(a[i] - a[i + 1]) == 1) {
                chkmin(ans, v);
            }
        }
        if (i) {
            if (a[i] != a[i - 1]) { 
                chkmin(ans, u);
            } else {
                chkmin(ans, u + v);
                chkmin(ans, 2 * v);
            }
            if (min(a[i], a[i - 1]) + 2 <= max(a[i], a[i - 1])) {
                chkmin(ans, 0);
            }
            if (abs(a[i] - a[i - 1]) == 1) {
                chkmin(ans, v);
            }
        }
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}