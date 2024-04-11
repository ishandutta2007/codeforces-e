#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> p(n * 2); REP(i, n * 2) cin >> p[i];
    vector<int> len;
    for (int i = 0; i < n * 2;) {
      int j = i + 1;
      while (j < n * 2 && p[j] < p[i]) ++j;
      len.emplace_back(j - i);
      i = j;
    }
    // REP(i, len.size()) cout << len[i] << " \n"[i + 1 == len.size()];
    vector dp(n + 1, false);
    dp[0] = true;
    for (int e : len) {
      for (int j = n; j >= 0; --j) {
        if (dp[j] && j + e <= n) dp[j + e] = true;
      }
    }
    cout << (dp[n] ? "YES\n" : "NO\n");
  }
  return 0;
}