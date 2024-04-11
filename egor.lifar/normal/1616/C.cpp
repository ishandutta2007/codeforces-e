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



int n;
int a[72];
ll ac[72], bc[72];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    ac[0] = 1;
    bc[0] = 0;
    ac[1] = 0;
    bc[1] = 1;
    for (int i = 2; i < n; i++) {
        ac[i] = 2LL * ac[i - 1] - ac[i - 2];
        bc[i] = 2LL * bc[i - 1] - bc[i - 2];
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
         //   ac[i] * x + bc[i] * y = a[i]
           // ac[j] * x + bc[j] * y = a[j]
            double x = double(a[i] * bc[j] - a[j] * bc[i]) / double(ac[i] * bc[j] - ac[j] * bc[i]);
            double y = double(a[i] * ac[j] - a[j] * ac[i]) / double(bc[i] * ac[j] - bc[j] * ac[i]);
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                double val = x * ac[k] + y * bc[k];
                if (abs(val - a[k]) < 1e-8) {
                    cnt++;
                }
            }
            chkmax(ans, cnt);
        }
    }
    cout << n -  ans << '\n';
}   


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}