#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 60) - 1;
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

vector< int > mobius_mu(int n) {
  vector< int > mu(n + 1, 1), p(n + 1, 1);
  for(int i = 2; i <= n; i++) {
    if(p[i] == 1) {
      for(int j = i; j <= n; j += i) p[j] = i;
    }
    if((i / p[i]) % p[i] == 0) mu[i] = 0;
    else mu[i] = -mu[i / p[i]];
  }
  return mu;
}


const int MAX_A = 100000;


int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;

  vector< int > exist(MAX_A + 1);
  int64 ret = 0;
  for(auto &p : A) {
    if(exist[p]) chmax(ret, p);
    exist[p] = true;
  }

  auto mu = mobius_mu(MAX_A);
  vector< int > g[MAX_A + 1];
  for(int i = 1; i <= MAX_A; i++) {
    for(int j = i; j <= MAX_A; j += i) {
      g[j].emplace_back(i);
    }
  }


  vector< int64 > coef(MAX_A + 1);

  vector< int > arr(N), st(N);

  for(int i = 1; i <= MAX_A; i++) {
    int ptr = 0;
    for(int j = i, k = 1; j <= MAX_A; j += i, k++) {
      if(exist[j]) arr[ptr++] = k;
    }
    if(ptr <= 1) continue;
    int top = -1;
    for(int j = ptr - 1; j >= 0; j--) {
      int64 all = 0;
      for(auto &k : g[arr[j]]) all += mu[k] * coef[k];
      while(all > 0) {
        if(__gcd(arr[j], st[top]) == 1) {
          chmax(ret, 1LL * i * arr[j] * st[top]);
          --all;
        }
        for(auto &k : g[st[top]]) coef[k]--;
        --top;
      }
      st[++top] = arr[j];
      for(auto &k : g[st[top]]) coef[k]++;
    }
    while(top >= 0) {
      for(auto &k : g[st[top]]) coef[k]--;
      top--;
    }
  }
  cout << ret << endl;
}