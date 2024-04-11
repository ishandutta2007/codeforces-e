#include<bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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


int main() {
  int N;
  cin >> N;
  vector< int > A(N - 1);
  cin >> A;

  int64 sum = 0;
  int64 low = 0, high = 0;
  for(int i = 0; i < A.size(); i++) {
    sum += A[i];
    chmin(low, sum);
    chmax(high, sum);
  }
  sum = -low;
  ++sum;
  vector< int64 > B;
  set< int > ex;
  B.emplace_back(sum);
  ex.emplace(sum);
  for(int i = 0; i < A.size(); i++) {
    sum += A[i];
    B.emplace_back(sum);
    ex.emplace(sum);
  }
  for(int i = 1; i <= N; i++) {
    if(!ex.count(i)) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(auto &p : B) cout << p << " ";
  cout << endl;
}