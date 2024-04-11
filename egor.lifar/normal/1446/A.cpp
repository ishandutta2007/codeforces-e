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
const int MAXN = 200228;


int n;
ll W;
ll w[MAXN];


void solve() {
	cin >> n >> W;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	vector<pair<ll, int> > st;
	for (int i = 0; i < n; i++) {
		if (w[i] >= (W + 1) / 2 && w[i] <= W) {
			cout << 1 << '\n';
			cout << i + 1 << '\n';
			return;
		}
		st.pb(mp(w[i], i));
	}
	sort(all(st));
	ll cur = 0;
	vector<int> res;
	for (auto x: st) {
		if (cur + x.first <= W) {
			cur += x.first;
			res.pb(x.second + 1);
		}
	}
	if (cur >= (W + 1) / 2 && cur <= W) {
		cout << sz(res) << '\n';
		for (auto x: res) {
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}
	cout << -1 << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}