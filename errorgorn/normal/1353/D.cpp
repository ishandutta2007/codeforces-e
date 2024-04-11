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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

struct cmp{
	operator() (ii i,ii j){
		if (i.se-i.fi!=j.se-j.fi) return i.se-i.fi<j.se-j.fi;
		return i.fi>j.fi;
	}
};

int n;
int arr[200005];
priority_queue<ii,vector<ii>, cmp> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		pq.push(ii(0,n-1));
		int index=1;
		
		while (!pq.empty()){
			int l=pq.top().fi,r=pq.top().se,m=l+r>>1;
			pq.pop();
			
			arr[m]=index++;
			if (l!=m) pq.push(ii(l,m-1));
			if (m!=r) pq.push(ii(m+1,r));
		}
		
		rep(x,0,n) cout<<arr[x]<<" ";
		cout<<endl;
	}
}