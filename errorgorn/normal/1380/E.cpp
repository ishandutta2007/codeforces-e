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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
set<int> s[200005];
bool used[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	int ans=n-1;
	
	rep(x,0,n){
		int t;
		cin>>t;
		
		if (s[t].count(x-1)){
			used[x]=true;
			ans--;
		}
		s[t].insert(x);
	}
	
	
	cout<<ans<<endl;
	
	int a,b;
	rep(x,1,k){
		cin>>a>>b;
		
		if (sz(s[a])<sz(s[b])) swap(s[a],s[b]);
		
		for (auto &it:s[b]){
			if (s[a].count(it-1) && !used[it]){
				used[it]=true;
				ans--;
			}
			if (s[a].count(it+1) && !used[it+1]){
				used[it+1]=true;
				ans--;
			}
			
			s[a].insert(it);
		}
		
		cout<<ans<<endl;
	}
}