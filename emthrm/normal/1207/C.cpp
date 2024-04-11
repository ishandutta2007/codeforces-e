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
#include <queue>
#include <random>
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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    int n; long long a, b; cin >> n >> a >> b;
    string s; cin >> s;
    vector<vector<long long> > dp(n + 1, vector<long long>(2, LINF));
    dp[0][0] = b;
    REP(i, n) {
      dp[i + 1][1] = min(dp[i][0] + a, dp[i][1]) + a + b * 2;
      if (s[i] == '0' && (i + 1 >= n || s[i + 1] == '0')) dp[i + 1][0] = min(dp[i][0], dp[i][1] + a) + a + b;
    }
    cout << dp[n][0] << '\n';
    // REP(i, n + 1) cout << dp[i][0] << ' ' << dp[i][1] << '\n';
  }
  return 0;
}