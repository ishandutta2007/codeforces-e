#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int L = 60;
const int N = 1e5+1;
vector<int> adj[N];
vector<int> vals[L];

int cycle(int s) {
	map<pii,int> dist;
	queue<pii> bfs;
	for(int v:adj[s]) {
		bfs.push(pii(v,s));
		dist[pii(v,s)]=1;
	}
	while(!bfs.empty()) {
		int u,p;tie(u,p)=bfs.front();bfs.pop();
		for(int v:adj[u]) {
			if(v!=p && !dist.count(pii(v,u))) {
				if(v==s) return dist[pii(u,p)]+1;
				dist[pii(v,u)]=dist[pii(u,p)]+1;
				bfs.push(pii(v,u));
			}
		}
	}
	return INF;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	ll v[n];
	vector<pii> edges;
	for(int i=0;i<n;i++) {
		cin>>v[i];
		for(int j=0;j<L;j++) {
			if(v[i]&1LL<<j) {
				vals[j].push_back(i);
			}
		}
	}
	for(int j=0;j<L;j++) {
		if(vals[j].size()>=3) {
			cout<<3<<nl;
			return 0;
		}
		if(vals[j].size()==2) {
			adj[vals[j][0]].push_back(vals[j][1]);
			adj[vals[j][1]].push_back(vals[j][0]);
		}
	}

	int ans = INF;
	for(int i=0;i<n;i++) {
		ans = min(ans, cycle(i));
	}
	if(ans==INF) cout<<-1<<nl;
	else cout<<ans<<nl;

	return 0;
}