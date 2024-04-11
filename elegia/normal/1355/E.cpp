#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b, m;
  cin >> n >> a >> b >> m;
  m = min(m, a + b);
  vector<int> h(n);
  cin >> h;

  auto calc = [&](int x) {
    ll l = 0, r = 0;
    for (int hv : h)
      if (hv <= x) l += x - hv;
      else r += hv - x;
    ll myn = min(l, r);
    l -= myn; r -= myn;
    return l * a + r * b + myn * m;
  };

  int l = 0, r = 1e9;
  while (r > l) {
    int mid = (l + r) >> 1;
    if (calc(mid) < calc(mid + 1))
      r = mid;
    else
      l = mid + 1;
  }
  cout << calc(l);

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}