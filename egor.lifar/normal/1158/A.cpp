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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 100228;


int n, m;
int b[MAXN];
int g[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> m;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		res += b[i];
	}
	long long res1 = 0;
	for (int i = 0; i < m; i++) {
		cin >> g[i];
		res1 += g[i];
	}
	if (1LL * res * m > 1LL * res1 * n) {
		cout << -1 << '\n';
		return 0;
	}
	sort(b, b + n);
	sort(g, g + m);
	if (g[0] < b[n - 1]) {
		cout << -1 << '\n';
		return 0;
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		ans += g[i];
	}
	bool was = false;
	for (int i = 0; i < m; i++) {
		if (g[i] == b[n - 1]) {
			was = true;
		}
	}
	if (was) {
		for (int i = 0; i < n - 1; i++) {
			ans += 1LL * m * b[i];
		}
	} else {
		for (int i = 0; i < n - 1; i++) {
			ans += 1LL * m * b[i];
		}
		ans += b[n - 1];
		ans -= b[n - 2];
	}
	cout << ans << '\n';
}