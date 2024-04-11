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
#define rank rank228
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 100228;


int m;



bool canwinds(ll l, ll r, int t = 0) {
	if (t == 0) {
		if (l * 2 >= r) {
			return 1;
		}
		return canwinds(l, (r + 1) / 2, 1);
	}
	if (r % 2 == 0 || l * 2 >= r) {
		return ((r - l) % 2) ^ 1;
	}
	return canwinds(l,  (r + 1) / 2, 0);
}


ll s[MAXN],e[MAXN];


int solve(int w) {
	for (int it = m - 1; it >= 0; it--) {
		w = canwinds(s[it], e[it] + 1, w);
		if (it != 0) {
			w ^= 1;
		}
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> m;
	for (int it = 0; it < m; it++) {
		cin >> s[it] >> e[it];
	}	
	cout << solve(1) << ' ' << solve(0) << '\n';
	return 0;	 	
}