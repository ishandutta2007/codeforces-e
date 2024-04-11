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

  vector<int> ichi(100), ni;
  iota(ALL(ichi), 0);
  int tmp = 128;
  while (ni.size() < 100) {
    ni.emplace_back(tmp);
    tmp += 128;
  }
  cout << "? ";
  REP(i, 100) {
    cout << ichi[i];
    if (i == 99) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  int ans1; cin >> ans1;
  ans1 &= 16256;
  cout << "? ";
  REP(i, 100) {
    cout << ni[i];
    if (i == 99) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  int ans2; cin >> ans2;
  ans2 &= 127;
  cout << "! " << (ans1 | ans2) << endl;
  return 0;
}