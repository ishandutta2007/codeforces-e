#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int a[300010];

void solve() {
	int n;
	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if(a[1] < a[n]) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	fast;
	int t;

	cin >> t;

	while(t--) {
		solve();
	}
}