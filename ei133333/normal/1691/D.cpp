#include<bits/stdc++.h>

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
 * @brief Segment Tree()
 * @docs docs/segment-tree.md
 */
template< typename Monoid, typename F >
struct SegmentTree {
  int n, sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree() = default;

  explicit SegmentTree(int n, const F f, const Monoid &M1) : n(n), f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  explicit SegmentTree(const vector< Monoid > &v, const F f, const Monoid &M1) :
      SegmentTree((int) v.size(), f, M1) {
    build(v);
  }

  void build(const vector< Monoid > &v) {
    assert(n == (int) v.size());
    for(int k = 0; k < n; k++) seg[k + sz] = v[k];
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void set(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid get(int k) const {
    return seg[k + sz];
  }

  Monoid operator[](const int &k) const {
    return get(k);
  }

  void apply(int k, const Monoid &x) {
    k += sz;
    seg[k] = f(seg[k], x);
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid prod(int l, int r) const {
    Monoid L = M1, R = M1;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, seg[l++]);
      if(r & 1) R = f(seg[--r], R);
    }
    return f(L, R);
  }

  Monoid all_prod() const {
    return seg[1];
  }

  template< typename C >
  int find_first(int l, const C &check) const {
    if(l >= n) return n;
    l += sz;
    Monoid sum = M1;
    do {
      while((l & 1) == 0) l >>= 1;
      if(check(f(sum, seg[l]))) {
        while(l < sz) {
          l <<= 1;
          auto nxt = f(sum, seg[l]);
          if(not check(nxt)) {
            sum = nxt;
            l++;
          }
        }
        return l + 1 - sz;
      }
      sum = f(sum, seg[l++]);
    } while((l & -l) != l);
    return n;
  }

  template< typename C >
  int find_last(int r, const C &check) const {
    if(r <= 0) return -1;
    r += sz;
    Monoid sum = 0;
    do {
      r--;
      while(r > 1 and (r & 1)) r >>= 1;
      if(check(f(seg[r], sum))) {
        while(r < sz) {
          r = (r << 1) + 1;
          auto nxt = f(seg[r], sum);
          if(not check(nxt)) {
            sum = nxt;
            r--;
          }
        }
        return r - sz;
      }
      sum = f(seg[r], sum);
    } while((r & -r) != r);
    return -1;
  }
};

template< typename Monoid, typename F >
SegmentTree< Monoid, F > get_segment_tree(int N, const F &f, const Monoid &M1) {
  return SegmentTree{N, f, M1};
}

template< typename Monoid, typename F >
SegmentTree< Monoid, F > get_segment_tree(const vector< Monoid > &v, const F &f, const Monoid &M1) {
  return SegmentTree{v, f, M1};
}

void beet() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  using pi = pair< int, int >;
  auto f = [](const pi &a, const pi &b) { return max(a, b); };
  vector< pi > seg_array(N);
  for(int i = 0; i < N; i++) seg_array[i] = {A[i], i};
  auto seg = get_segment_tree(seg_array, f, pi(-inf, -inf));
  queue< pair< int, int > > que;
  que.emplace(0, N);
  vector< int64 > S(N + 1);
  for(int i = 1; i <= N; i++) S[i] = A[i - 1] + S[i - 1];
  auto g = [](int64 a, int64 b) { return min(a, b); };
  auto h = [](int64 a, int64 b) { return max(a, b); };
  auto segMin = get_segment_tree(S, g, infll);
  auto segMax = get_segment_tree(S, h, -infll);
  while(not que.empty()) {
    auto[l, r] = que.front();
    que.pop();
    if(l + 1 >= r) continue;
    auto m = seg.prod(l, r).second;
    que.emplace(l, m);
    que.emplace(m + 1, r);
    auto x = segMin.prod(l, m + 1);
    auto y = segMax.prod(m + 1, r + 1);
    if(A[m] < y - x) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) beet();
}