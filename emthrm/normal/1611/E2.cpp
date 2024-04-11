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

void solve() {
  int n, k; cin >> n >> k;
  vector<int> x(k); REP(i, k) cin >> x[i], --x[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> vlad{0}, fri, is_visited(n, -1);
  is_visited[0] = 1;
  REP(i, k) {
    fri.emplace_back(x[i]);
    is_visited[x[i]] = 0;
  }
  while (!vlad.empty() || !fri.empty()) {
    vector<int> nx;
    for (int node : fri) {
      for (int e : graph[node]) {
        if (is_visited[e] == -1) {
          is_visited[e] = 0;
          nx.emplace_back(e);
        }
      }
    }
    fri.swap(nx);
    nx.clear();
    for (int node : vlad) {
      for (int e : graph[node]) {
        if (is_visited[e] == -1) {
          if (graph[e].size() == 1) {
            cout << "-1\n";
            return;
          }
          is_visited[e] = 1;
          nx.emplace_back(e);
        }
      }
    }
    vlad.swap(nx);
  }
  int ans = 0;
  REP(i, n) {
    if (is_visited[i] == 0) {
      ++ans;
      is_visited[i] = 2;
      queue<int> que({i});
      while (!que.empty()) {
        const int node = que.front(); que.pop();
        for (int e : graph[node]) {
          if (is_visited[e] == 0) {
            is_visited[e] = 2;
            que.emplace(e);
          }
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}