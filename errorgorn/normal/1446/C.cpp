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

int n;
int arr[200005];

int solve(vector<int> v){
	if (sz(v)<=1) return sz(v);
	vector<int> cnt[40];
	
	for (auto &it:v){
		if (it==0) cnt[32].push_back(it);
		else cnt[__builtin_clz(it)].push_back(it);
	}
	
	int ans=0;
	rep(x,33,0){
		int curr=0;
		rep(y,x+1,40) if (sz(cnt[y])) curr=1;
		vector<int> temp;
		for (auto &it:cnt[x]){
			temp.push_back(it^(1<<(max(31-x,0))));
		}
		curr+=solve(temp);
		rep(y,0,x) if (sz(cnt[y])) curr++;
		
		ans=max(ans,curr);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	vector<int> v;
	rep(x,0,n){
		int t;
		cin>>t;
		v.push_back(t);
	}
	
	cout<<n-solve(v)<<endl;
}