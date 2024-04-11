#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}


/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  vector< vector< int > > groups() {
    int n = (int) data.size();
    vector< vector< int > > ret(n);
    for(int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
      return v.empty();
    }));
    return ret;
  }
};

int main() {
  int N;
  cin >> N;
  vector< string > S(3);
  cin >> S;
  UnionFind uf(3 * N);
  auto get = [&](int y, int x) {
    return y * N + x;
  };
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < N; j++) {
      if(S[i][j] == '1') {
        if(i and S[i - 1][j] == '1') uf.unite(get(i, j), get(i - 1, j));
        if(j and S[i][j - 1] == '1') uf.unite(get(i, j), get(i, j - 1));
      }
    }
  }
  int Q;
  cin >> Q;

  vector< int > lcp(N + 1);
  for(int i = N - 1; i >= 0; i--) {
    if(S[0][i] == '1' and S[2][i] == '1' and S[1][i] == '0') {
      lcp[i] += lcp[i + 1];
      lcp[i] += 1;
    }
  }
  vector< int > scp(N);
  for(int i = 0; i < N; i++) {
    if(S[0][i] == '1' and S[2][i] == '1' and S[1][i] == '0') {
      if(i) scp[i] += scp[i - 1];
      scp[i] += 1;
    }
  }
  vector< int > x(3 * N, inf), y(3 * N, -inf);
  for(int i = 0; i < 3 * N; i++) {
    chmin(x[uf.find(i)], i % N);
    chmax(y[uf.find(i)], i % N);
  }
  vector< int > X(N + 1), Y(N + 1);
  int Z = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < N; j++) {
      if(S[i][j] == '1' and uf.find(get(i, j)) == get(i, j)) {
        Y[y[get(i, j)]]++;
        X[x[get(i, j)]]++;
        Z++;
      }
    }
  }
  for(int i = N - 1; i >= 0; i--) {
    X[i] += X[i + 1];
  }
  for(int i = 1; i <= N; i++) {
    Y[i] += Y[i - 1];
  }

  while(Q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int ret = 0;
    ret += Z;
    ret -= X[r + 1];
    if(l) ret -= Y[l - 1];
    if(S[0][l] == '1' and S[2][l] == '1' and S[1][l] == '0' and uf.same(get(0, l), get(2, l))) {
      int d = lcp[l];
      if(l + d > r) {
        ++ret;
      } else {
        if((S[0][l + d] == '1') + (S[1][l + d] == '1') + (S[2][l + d] == '1') <= 2) {
          ++ret;
        }
      }
    }
    if(S[0][r] == '1' and S[2][r] == '1' and S[1][r] == '0' and uf.same(get(0, r), get(2, r))) {
      int d = scp[r];
      if(r - d >= l) {
        if((S[0][r - d] == '1') + (S[1][r - d] == '1') + (S[2][r - d] == '1') <= 2) {
          ++ret;
        }
      }
    }
    cout << ret << "\n";
  }
}