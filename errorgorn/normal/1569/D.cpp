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

int n,m,k;
set<int> s,t;

map<int,int> ma[2000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		t.clear();
		
		cin>>n>>m>>k;
		
		int a,b;
		rep(x,0,n){
			cin>>a;
			s.insert(a);
			ma[a].clear();
		}
		rep(x,0,m){
			cin>>a;
			t.insert(a);
			ma[a+1000000].clear();
		}
		
		rep(x,0,k){
			cin>>a>>b;
			
			if (s.count(a) && t.count(b)) continue;
			
			if (s.count(a)) ma[*t.lb(b)+1000000][a]++;
			else ma[*s.lb(a)][b]++;
		}
		
		ll ans=0;
		for (auto &it:s){
			ll curr=0;
			for (auto &it2:ma[it]){
				//cout<<"s: "<<it<<" "<<it2.fi<<" "<<it2.se<<endl;
				ans+=curr*it2.se;
				curr+=it2.se;
			}
		}
		for (auto &it:t) if (it){
			ll curr=0;
			for (auto &it2:ma[it+1000000]){
				//cout<<"t: "<<it<<" "<<it2.fi<<" "<<it2.se<<endl;
				ans+=curr*it2.se;
				curr+=it2.se;
			}
		}
		
		cout<<ans<<endl;
	}
}