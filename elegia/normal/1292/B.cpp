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

  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll xs, ys, t;
  cin >> xs >> ys >> t;
  vector<pair<ll, ll>> nds;
  const ll INF = 3e16;
  while (x0 <= INF && y0 <= INF) {
    nds.emplace_back(x0, y0);
    x0 *= ax;
    x0 += bx;
    y0 *= ay;
    y0 += by;
  }
  auto dist = [&](ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  };
  int ans = 0;
  for (int rep = 0; rep < 2; ++rep) {
    for (int i = 0; i < nds.size(); ++i) {
      ll cur = dist(xs, ys, nds[i].first, nds[i].second);
      for (int j = i; j < nds.size(); ++j) {
        if (cur > t) break;
        ans = max(ans, j - i + 1);
        if (j + 1 < nds.size())
          cur += dist(nds[j].first, nds[j].second, nds[j + 1].first, nds[j + 1].second);
      }
    }
    reverse(nds.begin(), nds.end());
  }
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}