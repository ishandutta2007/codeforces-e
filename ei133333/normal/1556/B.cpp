#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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
 * @brief Binary-Indexed-Tree(BIT)
 * @docs docs/binary-indexed-tree.md
 */
template< typename T >
struct BinaryIndexedTree {
private:
  vector< T > data;

public:
  BinaryIndexedTree() = default;

  explicit BinaryIndexedTree(size_t sz) : data(sz + 1, 0) {}

  explicit BinaryIndexedTree(const vector< T > &vs) : data(vs.size() + 1, 0) {
    for(size_t i = 0; i < vs.size(); i++) data[i + 1] = vs[i];
    for(size_t i = 1; i < data.size(); i++) {
      size_t j = i + (i & -i);
      if(j < data.size()) data[j] += data[i];
    }
  }

  void add(int k, const T &x) {
    for(++k; k < (int) data.size(); k += k & -k) data[k] += x;
  }

  T fold(int r) const {
    T ret = T();
    for(; r > 0; r -= r & -r) ret += data[r];
    return ret;
  }

  T fold(int l, int r) const {
    return fold(r) - fold(l);
  }

  int lower_bound(T x) const {
    int i = 0;
    for(int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
      if(i + k < data.size() && data[i + k] < x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }

  int upper_bound(T x) const {
    int i = 0;
    for(int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
      if(i + k < data.size() && data[i + k] <= x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }
};

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector< int > A(N);
    cin >> A;
    for(auto &a: A) a &= 1;


    int64 ans = infll;
    {
      deque< int > g[2];
      BinaryIndexedTree< int > bit1(N), bit0(N);
      for(int i = 0; i < N; i++) {
        g[A[i]].emplace_back(i);
        if(A[i]) bit1.add(i, 1);
        else bit0.add(i, 1);
      }
      int64 ret = 0;
      for(int i = 0; i < N; i++) {
        if(i & 1) {
          if(g[0].empty()) {
            ret = infll;
            break;
          }
          int p = g[0].front();
          g[0].pop_front();
          ret += bit1.fold(p);
          bit0.add(p, -1);
        } else {
          if(g[1].empty()) {
            ret = infll;
            break;
          }
          int p = g[1].front();
          g[1].pop_front();
          ret += bit0.fold(p);
          bit1.add(p, -1);
        }
      }
      chmin(ans, ret);
    }
    {
      deque< int > g[2];
      BinaryIndexedTree< int > bit1(N), bit0(N);
      for(int i = 0; i < N; i++) {
        g[A[i]].emplace_back(i);
        if(A[i]) bit1.add(i, 1);
        else bit0.add(i, 1);
      }
      int64 ret = 0;
      for(int i = 0; i < N; i++) {
        if(i & 1) {
          if(g[1].empty()) {
            ret = infll;
            break;
          }
          int p = g[1].front();
          g[1].pop_front();
          ret += bit0.fold(p);
          bit1.add(p, -1);
        } else {
          if(g[0].empty()) {
            ret = infll;
            break;
          }
          int p = g[0].front();
          g[0].pop_front();
          ret += bit1.fold(p);
          bit0.add(p, -1);
        }
      }
      chmin(ans, ret);
    }
    if(ans >= infll) cout << -1 << "\n";
    else cout << ans << "\n";
  }
}