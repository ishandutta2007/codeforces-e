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

template< typename T, typename Compare = less< T >, typename RCompare = greater< T > >
struct PrioritySumStructure {

  size_t k;
  T sum;

  priority_queue< T, vector< T >, Compare > in, d_in;
  priority_queue< T, vector< T >, RCompare > out, d_out;

  PrioritySumStructure(int k) : k(k), sum(0) {}

  void modify() {
    while(in.size() - d_in.size() < k && !out.empty()) {
      auto p = out.top();
      out.pop();
      if(!d_out.empty() && p == d_out.top()) {
        d_out.pop();
      } else {
        sum += p;
        in.emplace(p);
      }
    }
    while(in.size() - d_in.size() > k) {
      auto p = in.top();
      in.pop();
      if(!d_in.empty() && p == d_in.top()) {
        d_in.pop();
      } else {
        sum -= p;
        out.emplace(p);
      }
    }
    while(!d_in.empty() && in.top() == d_in.top()) {
      in.pop();
      d_in.pop();
    }
  }

  T query() const {
    return sum;
  }

  void insert(T x) {
    in.emplace(x);
    sum += x;
    modify();
  }

  void erase(T x) {
    assert(size());
    if(!in.empty() && in.top() == x) {
      sum -= x;
      in.pop();
    } else if(!in.empty() && RCompare()(in.top(), x)) {
      sum -= x;
      d_in.emplace(x);
    } else {
      d_out.emplace(x);
    }
    modify();
  }

  void set_k(size_t kk) {
    k = kk;
    modify();
  }

  size_t get_k() const {
    return k;
  }

  size_t size() const {
    return in.size() + out.size() - d_in.size() - d_out.size();
  }
};

template< typename T >
using MaximumSum = PrioritySumStructure< T, greater< T >, less< T > >;

template< typename T >
using MinimumSum = PrioritySumStructure< T, less< T >, greater< T > >;


int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector< int > A(N);
  cin >> A;

  vector< int > X(N), Y(N);
  int S, T;
  cin >> S;
  while(S--) {
    int a;
    cin >> a;
    X[--a] = true;
  }
  cin >> T;
  while(T--) {
    int a;
    cin >> a;
    Y[--a] = true;
  }

  if(M < K) {
    cout << -1 << endl;
    return 0;
  }

  // M>=K

  vector< int64 > both{0}, latte{0}, malta{0}, other{0};
  for(int i = 0; i < N; i++) {
    if(X[i] && Y[i]) {
      both.emplace_back(A[i]);
    } else if(X[i]) {
      latte.emplace_back(A[i]);
    } else if(Y[i]) {
      malta.emplace_back(A[i]);
    } else {
      other.emplace_back(A[i]);
    }
  }
  sort(begin(both), end(both));
  sort(begin(latte), end(latte));
  sort(begin(malta), end(malta));
  sort(begin(other), end(other));
  MinimumSum< int64 > ms(0);
  int in = 0;
  for(int i = 1; i < both.size(); i++) {
    both[i] += both[i - 1];
  }
  for(int i = 1; i < latte.size(); i++) {
    latte[i] += latte[i - 1];
  }
  for(int i = 1; i < malta.size(); i++) {
    malta[i] += malta[i - 1];
  }
  for(int i = 1; i < other.size(); i++) {
    ms.insert(other[i]);
    ++in;
  }

  int64 ret = infll;
  // need
  int latte_need = (int) latte.size() - 1;
  int malta_need = (int) malta.size() - 1;
  for(int i = 0; i <= min(M, (int) both.size() - 1); i++) {
    if(i == M) {
      chmin(ret, both[i]);
    } else {
      int need = max(0, K - i);
      if(need + need + i > M) continue;
      if(need >= latte.size()) continue;
      if(need >= malta.size()) continue;
      while(latte_need > need) {
        ms.insert(latte[latte_need] - latte[latte_need - 1]);
        ++in;
        --latte_need;
      }
      while(malta_need > need) {
        ms.insert(malta[malta_need] - malta[malta_need - 1]);
        ++in;
        --malta_need;
      }
      int tap = M - i - need - need;
      if(tap > in) continue;
      ms.set_k(tap);
      chmin(ret, latte[need] + malta[need] + both[i] + ms.query());
    }
  }
  if(ret >= infll) ret = -1;
  cout << ret << endl;
}