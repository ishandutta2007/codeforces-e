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

struct node{
	int s,e,m;
	ll val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,ll k){
		if (s==e) val=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=__gcd(l->val,r->val);
		}
	}
	
	ll query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return __gcd(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,200005);

int n;
ll arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		rep(x,0,n-1) arr[x]=abs(arr[x]-arr[x+1]);
		rep(x,0,n-1) root->update(x,arr[x]);
		
		int ans=1;
		
		int l=0;
		rep(x,0,n-1){
			while (l<=x && root->query(l,x)==1) l++;
			ans=max(ans,x-l+2);
		}
		
		cout<<ans<<endl;
	}
}