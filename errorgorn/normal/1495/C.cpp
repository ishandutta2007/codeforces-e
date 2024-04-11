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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
string grid[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>grid[x];
		
		vector<int> v;
		if (n%3==0) v.pub(1);
		else v.pub(0);
		
		while (v.back()+3<n) v.pub(v.back()+3);
		
		for (auto &it:v){
			rep(x,0,m) grid[it][x]='X';
		}
		
		rep(x,0,sz(v)-1){
			if (grid[v[x]+1][1]=='X' || grid[v[x]+2][1]=='X'){
				grid[v[x]+1][1]=grid[v[x]+2][1]='X';
			}
			else{
				grid[v[x]+1][0]=grid[v[x]+2][0]='X';
			}
		}
		
		rep(x,0,n) cout<<grid[x]<<endl;
		cout<<endl;
	}
}