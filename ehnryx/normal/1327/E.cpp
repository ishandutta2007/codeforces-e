//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll n, int e) {
	ll r = 1;
	for( ; e>0; e/=2) {
		if(e&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		if(i == n) {
			cout << 10 << " ";
		} else {
			ll res = 10 * 9 * 2 * power(10, n-i-1) % MOD; // ends
			res += (ll)(n-i-1) * 10 * 9 * 9 * power(10, n-i-2) % MOD;
			cout << res % MOD << " ";
		}
	}
	cout << nl;

	return 0;
}