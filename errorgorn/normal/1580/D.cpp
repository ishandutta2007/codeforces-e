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

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n,m;
ll arr[4005];

vector<ll> v[4005];

int dnc(int L,int R){
	int mn=L;
	rep(x,L,R+1) if (arr[x]<arr[mn]) mn=x;
	
	vector<ll> l={0},r={0};
	if (L!=mn){
		int temp=dnc(L,mn-1);
		l=v[temp];
		rep(x,0,sz(l)) l[x]+=x*(m-x)*(arr[temp]-arr[mn]);
	}
	if (R!=mn){
		int temp=dnc(mn+1,R);
		r=v[temp];
		rep(x,0,sz(r)) r[x]+=x*(m-x)*(arr[temp]-arr[mn]);
	}
	
	v[mn].resize(sz(l)+sz(r));
	rep(x,0,sz(l)) rep(y,0,sz(r)){
		v[mn][x+y]=max(v[mn][x+y],l[x]+r[y]);
		v[mn][x+y+1]=max(v[mn][x+y+1],l[x]+r[y]);
	}
	
	// cout<<mn<<endl;
	// for (auto &it:v[mn]) cout<<it<<" "; cout<<endl;
	
	return mn;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	
	int temp=dnc(0,n-1);
	cout<<v[temp][m]<<endl;
}