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

int solve(int i){
	int res=-(i*i)*(n-1)+(arr[0]+i)*(arr[n-1]+i);
	
	rep(x,1,n-1){
		if (arr[x]+i<=0) res+=(arr[x]+i)*(arr[n-1]+i);
		else res+=(arr[x]+i)*(arr[0]+i);
	}
	
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		sort(arr,arr+n);
		
		const int INF=1e6+100;
		
		if (solve(-INF-1)>solve(-INF) || solve(INF)<solve(INF+1)){
			cout<<"INF"<<endl;
			continue;
		}
		
		int lo=-INF,hi=INF+1,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (solve(mi)<solve(mi+1)) lo=mi+1;
			else hi=mi;
		}
		
		cout<<max(solve(lo),solve(hi))<<endl;
	}
}