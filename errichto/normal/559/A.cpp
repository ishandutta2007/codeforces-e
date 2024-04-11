#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;

int t[6];
ll res;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	REP(i, 6) scanf("%d", &t[i]);
	while(1) {
		ll memo = res;
		REP(a, 6) {
			int b = (a + 1) % 6;
			int c = (a + 2) % 6;
			if(t[a] && t[c]) {
				res += 2LL * t[b] + 1;
				t[a]--;
				t[c]--;
				t[b]++;
			}
		}
		if(memo == res) break;
	}
	printf("%lld\n", res);
	
	return 0;
}