#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 1000000007;

int norm(int x) {
  return x >= P ? x - P : x;
}
void add(int& a, int b) {
  if ((a += b) >= P) {
    a -= P;
  }
}
void sub(int& a, int b) {
  if ((a -= b) < 0) {
    a += P;
  }
}
void fam(int& a, int b, int c) {
  a = (a + b * (ull)c) % P;
}
int mpow(int a, int k) {
  if (k == 0) {
    return 1;
  }
  int ret = mpow(a * (ull)a % P, k >> 1);
  if (k & 1) {
    ret = ret * (ull)a % P;
  }
  return ret;
}

const int _ = 250005;

int a[_], up[_], dn[_], stk[_];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int sz = 0;
    stk[0] = n + 1;
    for (int i = n; i; --i) {
      while (sz && a[stk[sz]] < a[i]) --sz;
      up[i] = stk[sz];
      stk[++sz] = i;
    }
    sz = 0;
    for (int i = n; i; --i) {
      while (sz && a[stk[sz]] > a[i]) --sz;
      dn[i] = stk[sz];
      stk[++sz] = i;
    }
    // for (int i = 1; i <= n; ++i) {
    //   cerr << i << ": " << up[i] << ' ' << dn[i] << '\n';
    // }
    int ans = 0, pos = 1;
    while (pos < n) {
      ++ans;
      if (a[pos + 1] > a[pos]) {
        int th = dn[pos] - 1;
        int q = pos;
        while (up[q] <= th) q = up[q];
        pos = q;
      } else {
        int th = up[pos] - 1;
        int q = pos;
        while (dn[q] <= th) q = dn[q];
        pos = q;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}