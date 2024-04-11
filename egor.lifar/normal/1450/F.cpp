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
const int MAXN = 100228;


int n;
int a[MAXN];
int cnt[MAXN];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int> > st;
    vector<int> cur;
    for (int i = 0; i < n; i++) {
        cur.pb(a[i]);
        if (i == n - 1 || a[i] == a[i + 1]) {
            st.pb(cur);
            cur.clear();
        }
    }
    int l = sz(st);
    int r = n + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
        for (auto x: st) {
            cnt[x[0]]++;
            cnt[x.back()]++;
        }
        int mx = mid + 1;
        int have = sz(st);
        for (auto x: st) {
            int last = 0;
            for (int i = 0; i < sz(x) - 1; i++) {
                if (cnt[x[i]] + 1 <= mx && cnt[x[i + 1]] + 1 <= mx) {
                    if (have < mid) {
                        have++;
                        cnt[x[i]]++; 
                        cnt[x[i + 1]]++;
                    }
                }   
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            chkmax(res, cnt[i]);
        }
        if (res > mx || have < mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l > n) {
        cout << -1 << '\n';
        return;
    }
    cout << l - 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //   read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}