#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, k, ans;
vi a;
vector<pii> b;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	forn(i, n) {
		cin >> k;
		if (k)
			a.pb(k);
	}

	sort(all(a));
	n = a.size();
	if (n > 0)
		b.pb(mp(a[0], 1));
	forab(i, 1, n)
		if (b.back().ff == a[i])
			b.back().ss++;
		else
			b.pb(mp(a[i], 1));

	ans = 0;
	forn(i, b.size()) {
		if (b[i].ss == 2) {
			ans++;
			continue;
		}
		if (b[i].ss == 1)
			continue;
		cout << -1;
		return 0;
	}

	cout << ans << '\n';

    return 0;
}