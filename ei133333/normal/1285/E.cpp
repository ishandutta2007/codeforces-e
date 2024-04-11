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


void beet() {
  int N;
  cin >> N;
  vector< int64 > L(N), R(N);
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    L[i] *= 4;
    R[i] *= 4;
    ++R[i];
  }
  vector< int64 > xs;
  for(int i = 0; i < N; i++) {
    for(int j = -2; j <= 2; j++) {
      xs.emplace_back(L[i] + j);
      xs.emplace_back(R[i] + j);
    }
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  vector< vector< int > > add(xs.size()), sub(xs.size());
  for(int i = 0; i < N; i++) {
    add[lower_bound(begin(xs), end(xs), L[i]) - begin(xs)].emplace_back(i);
    sub[lower_bound(begin(xs), end(xs), R[i]) - begin(xs)].emplace_back(i);
  }
  set< int > st;
  vector< vector< int > > candidate(N);
  vector< int > arr(xs.size());
  for(int i = 0; i < xs.size(); i++) {
    for(auto &p : add[i]) {
      st.emplace(p);
    }
    arr[i] = st.size();
    if(st.size() == 1) {
      candidate[*st.begin()].emplace_back(i);
    }
    for(auto &p : sub[i]) {
      st.erase(p);
    }
  }
  int sz = 0;
  for(int i = 1; i < xs.size(); i++) {
    if(arr[i - 1] == 0 && arr[i] >= 1) sz++;
  }
  int ret = 0;

  for(int i = 0; i < candidate.size(); i++) {
    int diff = sz;
    for(auto &p : candidate[i]) {
      if(p > 0 && arr[p - 1] == 0 && arr[p] >= 1) --diff;
      if(p + 1 < arr.size() && arr[p] == 0 && arr[p + 1] >= 1) --diff;
    }
    for(auto &p : candidate[i]) {
      arr[p]--;
    }
    for(auto &p : candidate[i]) {
      if(p > 0 && arr[p - 1] == 0 && arr[p] >= 1) ++diff;
      if(p + 1 < arr.size() && arr[p] == 0 && arr[p + 1] >= 1) ++diff;
    }
    chmax(ret, diff);
    for(auto &p : candidate[i]) {
      arr[p]++;
    }
  }
  cout << ret << endl;
}


int main() {
  int T;
  cin >> T;
  while(T--) beet();
}