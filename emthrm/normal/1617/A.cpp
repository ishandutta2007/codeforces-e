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

void solve() {
  string s, t; cin >> s >> t;
  sort(ALL(s));
  const int a = count(ALL(s), 'a');
  const int b = count(ALL(s), 'b');
  const int c = count(ALL(s), 'c');
  if (t == "abc" && a > 0 && b > 0 && c > 0) {
    reverse(ALL(s));
    while (!s.empty() && s.back() <= 'c') s.pop_back();
    reverse(ALL(s));
    cout << string(a, 'a') + string(c, 'c') + string(b, 'b') + s << '\n';
  } else {
    cout << s << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}