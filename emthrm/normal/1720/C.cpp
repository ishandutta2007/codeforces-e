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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  int ans = 0;
  REP(i, n) ans += count(ALL(s[i]), '1');
  if (ans == 0) {
    cout << 0 << '\n';
    return;
  }
  int init = 3;
  FOR(i, 1, n) FOR(j, 1, m) {
    vector<int> sq;
    for (const int dy : vector<int>{-1, 0}) {
      for (const int dx : vector<int>{-1, 0}) {
        sq.emplace_back(s[i + dy][j + dx] - '0');
      }
    }
    const int num = accumulate(ALL(sq), 0);
    if (num == 1) {
      chmin(init, 1);
    } else if (num >= 2) {
      chmin(init, num - 1);
    }
  }
  cout << ans - init + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}