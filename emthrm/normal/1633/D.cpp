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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  constexpr int B = 1000;
  int op[B + 1]{};
  fill(op, op + (B + 1), INF);
  op[1] = 0;
  queue<int> que({1});
  while (!que.empty()) {
    const int a = que.front(); que.pop();
    FOR(x, 1, a + 1) {
      const int nxt = a + a / x;
      if (nxt <= B && op[nxt] == INF) {
        op[nxt] = op[a] + 1;
        que.emplace(nxt);
      }
    }
  }
  const int m = *max_element(op + 1, op + (B + 1));

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> b(n), c(n);
    REP(i, n) cin >> b[i];
    REP(i, n) cin >> c[i];
    if (m * n <= k) {
      cout << accumulate(ALL(c), 0) << '\n';
      continue;
    }
    vector<int> dp(k + 1, -INF);
    dp[0] = 0;
    REP(i, n) for (int j = k - op[b[i]]; j >= 0; --j) {
      chmax(dp[j + op[b[i]]], dp[j] + c[i]);
    }
    cout << *max_element(ALL(dp)) << '\n';
  }
  return 0;
}