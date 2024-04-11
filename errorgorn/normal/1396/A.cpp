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

ll n;
ll arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	if (n==1){
		cout<<1<<" "<<1<<endl;
		cout<<-arr[0]<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	
	cout<<1<<" "<<n-1<<endl;
	rep(x,0,n-1) cout<<arr[x]*(n-1)<<" "; cout<<endl;
	cout<<2<<" "<<n<<endl;
	rep(x,1,n-1) cout<<0<<" ";
	cout<<arr[n-1]*(n-1)<<endl;
	cout<<1<<" "<<n<<endl;
	rep(x,0,n) cout<<arr[x]*(-n)<<" "; cout<<endl;
}