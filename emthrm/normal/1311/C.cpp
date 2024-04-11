#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; string s; cin >> n >> m >> s;
  vector<int> cnt(n + 1, 0);
  cnt[0] = m + 1;
  cnt[n] = -1;
  while (m--) {
    int p; cin >> p; --p;
    --cnt[p + 1];
  }
  FOR(i, 1, n + 1) cnt[i] += cnt[i - 1];
  vector<ll> ans(26, 0);
  REP(i, n) ans[s[i] - 'a'] += cnt[i];
  REP(i, 26) cout << ans[i] << " \n"[i + 1 == 26];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}