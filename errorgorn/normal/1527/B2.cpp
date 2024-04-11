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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		string s;
		
		cin>>n;
		cin>>s;
		
		string t=s;
		reverse(all(t));
		
		if (s!=t){
			int cnt=0;
			int mid=0;
			
			rep(x,0,n) if (s[x]=='0') cnt++;
			if (n%2==1 && s[n/2]=='0') mid=1;
			
			if (mid==1 && cnt==2) cout<<"DRAW"<<endl;
			else cout<<"ALICE"<<endl;
			continue;
		}
		
		int cnt=0;
		rep(x,0,n/2){
			if (s[x]=='0') cnt++;
		}
		
		int mid=0;
		if (n%2==1 && s[n/2]=='0') mid=1;
		
		if (mid==1){
			if (cnt==0) cout<<"BOB"<<endl;
			else cout<<"ALICE"<<endl;	
		}
		else{
			cout<<"BOB"<<endl;
		}
	}
}