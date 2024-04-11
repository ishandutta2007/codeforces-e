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
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, m; cin >> n >> m;
  vector s(n + 1, vector(m + 1, 0));
  REP(i, n) REP(j, m) {
    char c; cin >> c;
    s[i][j] = (c == 'W' ? 0 : 1);
  }
  REP(i, n) REP(j, m) s[i][j] = s[i][j] ^ s[i + 1][j] ^ s[i][j + 1] ^ s[i + 1][j + 1];
  int ans = 0;
  REP(i, n) ans += accumulate(ALL(s[i]), 0);
  FOR(i, 1, n) FOR(j, 1, m) {
    if (s[i - 1][j - 1] == 1 && s[n - 1][j - 1] == 1 && s[i - 1][m - 1] == 1 && s[n - 1][m - 1] == 1) {
      cout << ans - 1 << '\n';
      return 0;
    }
  }
  cout << ans << '\n';
  return 0;
}