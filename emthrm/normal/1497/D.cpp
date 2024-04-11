#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> tag(n), s(n);
  REP(i, n) cin >> tag[i];
  REP(i, n) cin >> s[i];
  vector<ll> dp(n, 0);
  REP(i, n) {
    for (int j = i - 1; j >= 0; --j) {
      if (tag[j] != tag[i]) {
        ll tmp = dp[j];
        chmax(dp[j], dp[i] + abs(s[j] - s[i]));
        chmax(dp[i], tmp + abs(s[i] - s[j]));
      }
    }
  }
  cout << *max_element(ALL(dp)) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}