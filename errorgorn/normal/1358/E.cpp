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

int n;
ll arr[250005];
ll pre[250005];
ll val;

multiset<ll> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,(n+1)/2) cin>>arr[x];
	cin>>val;
	
	pre[(n+1)/2]=val*(n/2+1);
	rep(x,(n+1)/2,0){
		pre[x]=pre[x+1]+arr[x]-val;
		s.insert(pre[x]);
	}
	
	//for (auto &it:s) cout<<it<<" ";
	//cout<<endl;
	
	if (*s.begin()>0){
		cout<<n/2+1;
		return 0;
	}
	
	ll delta=0;
	rep(x,(n+1)/2,1){
		delta+=val;
		
		s.erase(s.find(pre[x]));
		
		//for (auto &it:s) cout<<it+delta<<" ";
		//cout<<endl;
		
		if (*s.begin()+delta>0){
			cout<<n-x+1<<endl;
			return 0;
		}
	}
	
	cout<<"-1"<<endl;
	
}