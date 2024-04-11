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
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int l,r;

vector<tuple<int,int,int> > edges;
int idx[40];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int IDX=31;
	rep(x,0,21){
		edges.pub({IDX,32,1});
		int d=1;
		rep(y,0,x) edges.pub({IDX,idx[y],d}),d+=(1<<y);
		idx[x]=IDX--;
	}
	
	cin>>l>>r;
	
	edges.pub({1,32,l});
	l++;
	
	rep(x,21,0){
		if (l+(1<<x)-1<=r){
			edges.pub({1,idx[x],l-1});
			l+=(1<<x);
		}
	}
	
	cout<<"YES"<<endl;
	cout<<32<<" "<<sz(edges)<<endl;
	for (auto &it:edges){
		int a,b,c;
		tie(a,b,c)=it;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
}