//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int n;
vector<string> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		v.clear();
		cin>>n;
		
		string s;
		rep(x,0,3){
			cin>>s;
			v.pub(s);
		}
		
		sort(all(v));
		
		string ans;
		do{
			vector<int> p[2][2];
			
			rep(x,0,2) rep(y,0,2*n){
				p[x][v[x][y]-'0'].pub(y);
			}
			
			if (sz(p[0][1])>=n && sz(p[1][1])>=n){
				swap(p[0][0],p[0][1]);
				swap(p[1][0],p[1][1]);
			}
			
			if (sz(p[0][0])>=n && sz(p[1][0])>=n){
				while (sz(p[0][0])>n) p[0][0].pob();
				while (sz(p[1][0])>n) p[1][0].pob();
				p[0][0].pub(2*n);
				p[1][0].pub(2*n);
				
				ans="";
				int curr=0;
				
				rep(x,0,p[0][0][0]) ans+=v[0][x];
				rep(x,0,p[1][0][0]) ans+=v[1][x];
				
				rep(x,0,n){
					ans+=v[0][p[0][0][x]];
					rep(y,p[0][0][x]+1,p[0][0][x+1]) ans+=v[0][y];
					rep(y,p[1][0][x]+1,p[1][0][x+1]) ans+=v[1][y];
				}
			}
			
		} while (next_permutation(all(v)));
		
		cout<<ans<<endl;
	}
}