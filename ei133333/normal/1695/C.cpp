#include<bits/stdc++.h>

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

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    auto a = make_v< int >(n, m);
    cin >> a;
    auto dp_low = make_v< int >(n, m);
    auto dp_high = make_v< int >(n, m);
    fill_v(dp_low, inf);
    fill_v(dp_high, -inf);
    dp_low[0][0] = a[0][0];
    dp_high[0][0] = a[0][0];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i) {
          chmin(dp_low[i][j], dp_low[i - 1][j] + a[i][j]);
          chmax(dp_high[i][j], dp_high[i - 1][j] + a[i][j]);
        }
        if(j) {
          chmin(dp_low[i][j], dp_low[i][j - 1] + a[i][j]);
          chmax(dp_high[i][j], dp_high[i][j - 1] + a[i][j]);
        }
      }
    }
    if(dp_low[n - 1][m - 1] % 2 == 0 and dp_low[n - 1][m - 1] <= 0 and 0 <= dp_high[n - 1][m - 1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}