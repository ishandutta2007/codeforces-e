#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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
 * @brief Montgomery ModInt
 */
template< uint32_t mod, bool fast = false >
struct MontgomeryModInt {
  using mint = MontgomeryModInt;
  using i32 = int32_t;
  using i64 = int64_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for(i32 i = 0; i < 4; i++) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;

  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 x;

  MontgomeryModInt() : x{} {}

  MontgomeryModInt(const i64 &a)
      : x(reduce(u64(fast ? a : (a % mod + mod)) * n2)) {}

  static constexpr u32 reduce(const u64 &b) {
    return u32(b >> 32) + mod - u32((u64(u32(b) * r) * mod) >> 32);
  }

  mint &operator+=(const mint &p) {
    if(i32(x += p.x - 2 * mod) < 0) x += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &p) {
    if(i32(x -= p.x) < 0) x += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &p) {
    x = reduce(u64(x) * p.x);
    return *this;
  }

  mint &operator/=(const mint &p) {
    *this *= p.inverse();
    return *this;
  }

  mint operator-() const { return mint() - *this; }

  mint operator+(const mint &p) const { return mint(*this) += p; }

  mint operator-(const mint &p) const { return mint(*this) -= p; }

  mint operator*(const mint &p) const { return mint(*this) *= p; }

  mint operator/(const mint &p) const { return mint(*this) /= p; }

  bool operator==(const mint &p) const { return (x >= mod ? x - mod : x) == (p.x >= mod ? p.x - mod : p.x); }

  bool operator!=(const mint &p) const { return (x >= mod ? x - mod : x) != (p.x >= mod ? p.x - mod : p.x); }

  u32 get() const {
    u32 ret = reduce(x);
    return ret >= mod ? ret - mod : ret;
  }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  mint inverse() const {
    return pow(mod - 2);
  }

  friend ostream &operator<<(ostream &os, const mint &p) {
    return os << p.get();
  }

  friend istream &operator>>(istream &is, mint &a) {
    i64 t;
    is >> t;
    a = mint(t);
    return is;
  }

  static u32 get_mod() { return mod; }
};

using modint = MontgomeryModInt< mod, true >;

int main() {

  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  auto ctz = make_v< int >(1 << N);
  for(int i = 1; i < (1 << N); i++) {
    ctz[i] = __builtin_ctz(i);
  }
  auto B = make_v< modint >(N, N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      B[i][j] = modint(A[i]) / (A[i] + A[j]);
    }
  }
  auto C = make_v< modint >(N, 1 << N);
  auto D = make_v< modint >(N, 1 << N);
  for(int i = 0; i < N; i++) {
    C[i][0] = 1;
    for(int j = 1; j < (1 << N); j++) {
      C[i][j] = B[i][ctz[j]] * C[i][j ^ (1 << ctz[j])];
      D[i][j] = C[i][j].inverse();
    }
  }
  auto E = make_v< modint >(1 << N);
  auto F = make_v< modint >(1 << N);
  for(int i = 0; i < (1 << N); i++) {
    E[i] = modint(1);
    for(int j = 0; j < N; j++) {
      if(i & (1 << j)) E[i] *= C[j][i];
    }
    F[i] = E[i].inverse();
  }

  auto coef = [&](int from, int to) {
    modint x = modint(1);
    while(from) {
      x *= C[ctz[from]][to];
      from ^= 1 << ctz[from];
    }
    return x;
  };
  vector< modint > dp(1 << N, modint(1));
  vector< modint > dp3(1 << N);
  for(int i = 1; i < (1 << N); i++) {
    dp3[i] = E[i];
    for(int j = i & (i - 1); j > 0; j = (j - 1) & i) {
      int f = i ^ j;
      dp3[j] = dp3[j | (1 << ctz[f])] * D[ctz[f]][i];
      dp[i] -= dp[j] * dp3[j] * F[j];
    }
  }
  modint ret = 0;
  vector< modint > dp2(1 << N);
  for(int i = 1; i < (1 << N); i++) {
    dp[i] *= coef(i, i ^ ((1 << N) - 1));
    ret += dp[i] * __builtin_popcount(i);
  }
  cout << ret << "\n";
}