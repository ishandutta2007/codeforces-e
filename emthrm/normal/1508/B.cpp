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

template <typename Abelian>
struct BIT {
  BIT(int n, const Abelian ID = 0) : n(n), ID(ID), dat(n, ID) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat;
};

ll p2[100001]{};

void solve() {
  int n; ll k; cin >> n >> k;
  if (p2[n - 1] < k) {
    cout << "-1\n";
    return;
  }
  --k;
  vector<int> a(n, -1);
  for (int i = 0; i < n;) {
    int use = 1;
    for (int j = n - 2 - i; j >= 0 && k >= p2[j]; --j) {
      ++use;
      k -= p2[j];
    }
    REP(j, use) a[i + j] = i + use - 1 - j;
    i += use;
  }
  assert(k == 0);
  REP(i, n) cout << a[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  p2[0] = 1;
  REP(i, 100000) p2[i + 1] = min(p2[i] * 2, LINF);

  int t; cin >> t;
  while (t--) solve();
  return 0;

  // vector<int> a(n);
  // iota(ALL(a), 0);
  // do {
  //   bool is_almost_sorted = true;
  //   FOR(i, 1, n) is_almost_sorted &= a[i] >= a[i - 1] - 1;
  //   if (is_almost_sorted) {
  //     REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  //   }
  // } while (next_permutation(ALL(a)));
}