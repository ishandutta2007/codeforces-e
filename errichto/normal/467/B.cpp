#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

int t[nax], x;

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	RI(i, m) cin >> t[i];
	cin >> x;
	int licz = 0;
	RI(i, m) if(__builtin_popcount(x ^ t[i]) <= k) licz++;
	cout << licz;
	
	return 0;
}