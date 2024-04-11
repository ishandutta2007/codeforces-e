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

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  cin >> l;
  vector<int> len(m);
  int cur = 0;
  for (int i = m - 1; i >= 0; --i) {
    cur = max(cur + 1, l[i]);
    len[i] = cur;
  }
  cerr << cur << '\n';
  if (cur > n) {
    cout << "-1\n";
    return 0;
  }
  ll tot = accumulate(l.begin(), l.end(), 0LL);
  if (tot < n) {
    cout << "-1\n";
    return 0;
  }
  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    p[i] = n - len[i] + 1;
  }
  int fil = 1;
  for (int i = 0; i < m; ++i) {
    if (fil >= p[i]) break;
    p[i] = fil;
    fil += l[i];
  }
  cout << p << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}