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
int arr[100005];
int brr[100005];
int idx[100005];

vector<int> al[100005];
bool vis[100005];

void dfs(int i){
	if (vis[i]) return;
	vis[i]=true;
	
	for (auto &it:al[i]){
		dfs(it);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) al[x].clear();
		
		rep(x,0,n) cin>>arr[x];
		rep(x,0,n) cin>>brr[x];
		
		rep(x,0,n) idx[x]=x;
		sort(idx,idx+n,[](int i,int j){
			return brr[i]<brr[j];
		});
		
		// rep(x,0,n) cout<<idx[x]<<" "; cout<<endl;
		// rep(x,0,n) cout<<arr[idx[x]]<<" "; cout<<endl;
		
		rep(x,1,n){
			al[idx[x-1]].pub(idx[x]);
		}
		
		vector<ii> v;
		rep(x,n,0){
			if (v.empty() || v.back().fi>arr[idx[x]]) v.pub({arr[idx[x]],idx[x]});
			else{
				int lo=-1,hi=sz(v)-1,mi;
				while (hi-lo>1){
					mi=hi+lo>>1;
					
					if (v[mi].fi>arr[idx[x]]) lo=mi;
					else hi=mi;
				}
				
				//cout<<"debug: "<<idx[x]<<" "<<v[hi].se<<endl;
				al[v[hi].se].pub(idx[x]);
			}
		}
		
		rep(x,0,n) vis[x]=false;
		dfs(idx[n-1]);
		
		rep(x,0,n){
			if (vis[x]) cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
}