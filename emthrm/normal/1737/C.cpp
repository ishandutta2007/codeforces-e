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
  int n; cin >> n;
  int r[3], c[3]; REP(i, 3) cin >> r[i] >> c[i], --r[i], --c[i];
  sort(r, r + 3);
  sort(c, c + 3);
  int x, y; cin >> x >> y; --x; --y;
  if (r[1] == 0) {
    if (c[1] == 0) {
      cout << (x == 0 || y == 0 ? "YES\n" : "NO\n");
      return;
    } else if (c[1] == n - 1) {
      cout << (x == 0 || y == n - 1 ? "YES\n" : "NO\n");
      return;
    }
  } else if (r[1] == n - 1) {
    if (c[1] == 0) {
      cout << (x == n - 1 || y == 0 ? "YES\n" : "NO\n");
      return;
    } else if (c[1] == n - 1) {
      cout << (x == n - 1 || y == n - 1 ? "YES\n" : "NO\n");
      return;
    }
  }
  cout << (abs(x - r[1]) % 2 == 0 || abs(y - c[1]) % 2 == 0 ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}