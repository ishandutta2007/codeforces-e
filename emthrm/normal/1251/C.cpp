#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  int t; cin >> t;
  while (t--) {
    string a; cin >> a;
    vector<vector<int> > digits(2);
    for (char c : a) {
      int now = c - '0';
      digits[now & 1].emplace_back(now);
    }
    REP(i, 2) reverse(ALL(digits[i]));
    string ans = "";
    while (!digits[0].empty() || !digits[1].empty()) {
      if (digits[0].empty()) {
        ans += '0' + digits[1].back();
        digits[1].pop_back();
        continue;
      }
      if (digits[1].empty()) {
        ans += '0' + digits[0].back();
        digits[0].pop_back();
        continue;
      }
      if (digits[0].back() < digits[1].back()) {
        ans += '0' + digits[0].back();
        digits[0].pop_back();
      } else {
        ans += '0' + digits[1].back();
        digits[1].pop_back();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}