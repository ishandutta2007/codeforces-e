 /*
 



















 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
const string FILENAME = "input";
const int MAXN = 300228;


int n;
long long a[MAXN];
long long dp[MAXN][15];
long long pref[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pref[i] = a[i];
		if (i) {
			pref[i] += pref[i - 1];
		}
	}
	long long cur = 0;
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			cur = max(0LL, cur - 1);
			continue;
		}
		long long cnt = (i == 0 ? 0: pref[i - 1]);
		if (cnt < cur) {
			a[i] -= cur - cnt;
			ans += a[i] / 3;
			break;
		}
		long long g = min((a[i] % 2 == 1 ? a[i] / 2 - 1: a[i] / 2), cnt - cur);
		cur += g;
		a[i] -= g * 2;
		ans+= g;
		ans += a[i] / 3;
		a[i] %= 3;
		cur = max(0LL, cur - a[i]);
	}
	cout << ans << '\n';
	return 0; 	
}