// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
vector<int> al[200005];

int ans=0;
int dfs(int i,int p){
	vector<int> child={0};
	
	for (auto it:al[i]){
		if (it==p) continue;
		child.pub(dfs(it,i));
	}
	
	sort(all(child));
	reverse(all(child));
	
	if (arr[i]<child[0]) return child[0];
	else{
		ans+=arr[i]-child[0];
		if (p==-1){
			if (sz(child)==2) ans+=arr[i];
			else ans+=arr[i]-child[1];
		}
		return arr[i];
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].pub(b);
		al[b].pub(a);
	}
	
	int idx=-1;
	int best=0;
	rep(x,1,n+1){
		if (best<arr[x]){
			best=arr[x];
			idx=x;
		}
	}
	
	dfs(idx,-1);
	
	cout<<ans<<endl;
}