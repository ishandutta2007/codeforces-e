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

void output(int l1, int r1, int l2, int r2) {
  cout << l1 + 1 << ' ' << r1 + 1 << ' ' << l2 + 1 << ' ' << r2 + 1 << '\n';
}

void solve() {
  int n; string s; cin >> n >> s;
  FOR(i, n / 2, n) {
    if (s[i] == '0') {
      output(0, i, 0, i - 1);
      return;
    }
  }
  if (n % 2 == 0) {
    if (s[n / 2 - 1] == '1') {
      output(n / 2 - 1, n - 2, n / 2, n - 1);
    } else {
      output(n / 2 - 1, n - 1, n / 2, n - 1);
    }
  } else {
    output(n / 2, n - 2, n / 2 + 1, n - 1);
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}