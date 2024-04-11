#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

#include <bits/stdc++.h>

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


int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    int64 X;
    cin >> N >> K >> X;
    string S;
    cin >> S;
    vector< pair< char, int64 > > run;
    for(auto &s: S) {
      if(run.empty() or run.back().first != s) {
        run.emplace_back(s, 0);
      }
      run.back().second++;
    }
    vector< int64 > ways(run.size() + 1);
    ways.back() = 1;
    for(int i = (int) run.size() - 1; i >= 0; i--) {
      int64 d = run[i].first == '*' ? 1LL * run[i].second * K + 1 : 1;
      ways[i] = min((__int128_t) ways[i + 1] * d, (__int128_t) infll);
    }
    string ret;
    for(int i = 0; i < (int) run.size(); i++) {
      int64 d = run[i].first == '*' ? 1LL * run[i].second * K + 1 : 1;
      if(run[i].first == 'a') {
        while(run[i].second--) ret += 'a';
      } else {
        for(int64 j = 0; j <= 1LL * run[i].second * K; j++) {
          if(X - ways[i + 1] > 0) {
            X -= ways[i + 1];
            if(j) ret += 'b';
          } else {
            if(j) ret += 'b';
            break;
          }
        }
      }
    }
    cout << ret << "\n";
  }
}