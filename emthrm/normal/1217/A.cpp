#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    long long str, in, exp; cin >> str >> in >> exp;
    // double tmp = (in + exp - str) / 2.0;
    // long long a = ceil(tmp);
    // if (tmp == a) ++a;
    // cout << max(exp - a + 1, 0LL) << '\n';
    long long lb = -1, ub = exp + 1;
    while (ub - lb > 1) {
      long long mid = (ub + lb) / 2;
      (str + mid > in + exp - mid ? ub : lb) = mid;
    }
    cout << exp - ub + 1 << '\n';
  }
  return 0;
}