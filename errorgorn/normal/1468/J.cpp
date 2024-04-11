//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
vector<iii> edges;

int p[200005];
int par(int i){
	if (p[i]==i) return i;
	else return p[i]=par(p[i]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		edges.clear();
		
		cin>>n>>m>>k;
		
		int a,b,c;
		rep(x,0,m){
			cin>>a>>b>>c;
			edges.push_back(iii(ii(a,b),c));
		}
		
		sort(all(edges),[](iii i,iii j){
			return i.se<j.se;
		});
		
		rep(x,1,n+1) p[x]=x;
		
		ll ans=0;
		for (auto &it:edges){
			if (par(it.fi.fi)!=par(it.fi.se)){
				ans+=max(0LL,it.se-k);
				p[par(it.fi.fi)]=par(it.fi.se);
			}
		}
		
		if (ans==0){
			ans=1e9;
			for (auto &it:edges) ans=min(ans,abs(it.se-k));
		}
		
		cout<<ans<<endl;
	}
}