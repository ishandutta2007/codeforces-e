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
const int MAXN = 5005;
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b % Mod);
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}

int n;
int a[MAXN];
int dp[MAXN][MAXN];
int pref[MAXN][MAXN];
int fact[MAXN];
int rfact[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// /read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 0; i <= n; i++) {
		rfact[i] = powm(fact[i], Mod - 2);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	int uk = 0;
	for (int i = 0; i < n; i++) {
		while (a[uk] * 2 <= a[i]) {
			uk++;
		}
		for (int j = 0; j < i; j++) {
			dp[i][j + 1] = sum(dp[i][j + 1], pref[j][uk]);
		}
		for (int j = 0; j < uk; j++) {
			dp[i][j + 1] = sum(dp[i][j + 1], mul(dp[i][j], uk - j));
		}
		for (int j = 0; j <= i; j++) {
			pref[j][i + 1] = sum(pref[j][i], dp[i][j]);
		}
	}
	cout << dp[n - 1][n - 1] << '\n';
	return 0;
}