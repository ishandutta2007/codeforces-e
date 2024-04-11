#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in: v) is >> in;
  return is;
}

template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template<typename T = int64>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
  t = v;
}

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
  for (auto &e: t) fill_v(e, v);
}

template<typename F>
struct FixPoint : F {
  explicit FixPoint(F &&f) : F(forward<F>(f)) {}

  template<typename... Args>
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
inline decltype(auto) MFP(F &&f) {
  return FixPoint<F>{forward<F>(f)};
}

#line 2 "graph/graph-template.hpp"

/**
 * @brief Graph Template()
 */
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }

  inline vector< Edge< T > > &operator[](const int &k) {
    return g[k];
  }

  inline const vector< Edge< T > > &operator[](const int &k) const {
    return g[k];
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  Graph<> g(N);
  g.read(N - 1);
  auto S = A;
  MFP([&](auto dfs, int idx, int par) -> void {
    if(~par) S[idx] ^= S[par];
    for(auto& to : g[idx]) {
      if(to != par) dfs(to, idx);
    }
  }) (0, -1);
  vector< set< int > > vs(N);
  auto dfs = MFP([&](auto dfs, int idx, int par) -> int {
    int ret = 0;
    bool flag = false;
    for(auto& to : g[idx]) {
      if(to != par) {
        ret += dfs(to, idx);
        if(vs[to].count(A[idx] ^ S[idx])) {
          flag = true;
        }
        if(vs[to].size() > vs[idx].size()) {
          vs[idx].swap(vs[to]);
        }
        for(auto& x : vs[to]) {
          if (vs[idx].count(x ^ A[idx])) {
            flag = true;
          }
        }
        for(auto& x : vs[to]) {
          vs[idx].emplace(x);
        }
        vs[to].clear();
      }
    }
    vs[idx].emplace(S[idx]);
    if(flag) {
      ++ret;
      vs[idx].clear();
    }
    return ret;
  });
  cout << dfs(0, -1) << endl;
}