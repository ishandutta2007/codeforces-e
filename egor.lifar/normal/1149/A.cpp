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
const string FILENAME = "input";
const int MAXN = 300228;


int n;
int a[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 //	read(FILENAME);
 	cin >> n;
 	int cnt[3] = {0, 0, 0};
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 		cnt[a[i]]++;
 	}
 	if (cnt[2]) {
 		cout << 2 << ' ';
 		cnt[2]--;
 	}
 	if (cnt[1]) {
 		cout << 1 << ' ';
 		cnt[1]--;
 	}
 	for (int i = 0; i < cnt[2]; i++) {
 		cout << 2 << ' ';
 	}
 	for (int i = 0; i < cnt[1]; i++) {
 		cout << 1 << ' ';
 	}
 	cout << '\n';
	return 0; 	
}