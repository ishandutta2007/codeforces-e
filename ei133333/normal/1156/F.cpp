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
  for(T &in : v) is >> in;
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
  for(auto &e : t) fill_v(e, v);
}

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
};

using modint = ModInt< mod >;

template< typename T >
struct Combination {
  vector< T > _fact, _rfact;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1) {
    _fact[0] = _rfact[sz] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

int N;
vector< int > S, T;
modint inv[5005];
int dp[5005][5005];

modint rec(int idx, int used);


int rec2(int idx, int used) { // idx
  if(~dp[idx][used]) return dp[idx][used];
  if(idx == N) return 0;
  modint ret = inv[T[idx]] * T[idx + 1] * rec2(idx + 1, used + S[idx]);
  if(S[idx]) ret += inv[T[idx]] * S[idx] * rec(idx, used);
  return dp[idx][used] = ret.x;
}

modint rec(int idx, int used) {
  modint ret = S[idx] - 1; // 
  ret += modint(T[idx + 1]) * rec2(idx + 1, used + S[idx] - 1);
  return ret * inv[used + T[idx] - 1];
}

int main() {

  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < 5005; i++) {
    inv[i] = modint(i).inverse();
  }

  cin >> N;
  S.resize(N);
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    --x;
    S[x]++;
  }
  T = S;
  for(int i = N - 2; i >= 0; i--) {
    T[i] += T[i + 1];
  }
  T.push_back(0);
  modint ret = 0;
  int loss = 0;
  modint all = inv[N];
  for(int i = 0; i < N; i++) {
    if(S[i]) ret += rec(i, loss) * all * S[i];
    loss += S[i];
  }
  cout << ret << endl;
}