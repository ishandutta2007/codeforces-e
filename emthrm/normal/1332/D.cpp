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
  const int X = 1 << 17;
  int k; cin >> k;
  cout << "3 3\n";
  cout << (k | X) << ' ' << (k | X) << ' ' << X << '\n';
  cout << X << ' ' << k << ' ' << (k | X) << '\n';
  cout << X << ' ' << (k | X) << ' ' << k << '\n';
  return 0;

  // int n, m; cin >> n >> m;
  // vector<vector<int>> a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  // vector<vector<int>> dp(n, vector<int>(m, 0));
  // dp[0][0] = a[0][0];
  // REP(i, n) REP(j, m) {
  //   if (i > 0) chmax(dp[i][j], dp[i - 1][j] & a[i][j]);
  //   if (j > 0) chmax(dp[i][j], dp[i][j - 1] & a[i][j]);
  // }
  // REP(i, n) REP(j, m) cout << bitset<4>(dp[i][j]) << " \n"[j + 1 == m];
}