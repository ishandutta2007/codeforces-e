#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<string> s(n); REP(i, n) cin >> s[i];
  REP(i, 2) REP(j, 2) {
    if (i == j) continue;
    vector<pair<int, int>> ans;
    if (s[1][0] - '0' != i) ans.emplace_back(1, 0);
    if (s[0][1] - '0' != i) ans.emplace_back(0, 1);
    if (s[n - 2][n - 1] - '0' != j) ans.emplace_back(n - 2, n - 1);
    if (s[n - 1][n - 2] - '0' != j) ans.emplace_back(n - 1, n - 2);
    if (ans.size() <= 2) {
      cout << ans.size() << '\n';
      for (auto [y, x] : ans) cout << y + 1 << ' ' << x + 1 << '\n';
      return;
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}