#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid ((s + e)>>1)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int t, n, x;
void solve(){
	cin >> n;
	vi v;
	while(n--){
		cin >> x;
		v.pb(x);
	}
	sort(all(v));
	int s = 0, e = v.size() - 1;
	vi ans;
	while(e - s + 1){
		ans.pb((s+e)&1 ? v[e--] : v[s++]);
	}
	reverse(all(ans));
	for(auto a : ans)cout << a << " ";
	cout << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}