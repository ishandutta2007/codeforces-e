#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 105;

int tot[nax];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		pii best = mp(-1,-1);
		RI(i,n) {
			int a;
			scanf("%d", &a);
			if(a > best.st)
				best = mp(a, i);
		}
		assert(best.nd != -1);
		tot[best.nd]++;
	}
	pii best = mp(-1,-1);
	RI(i,n) if(tot[i] > best.st)
		best = mp(tot[i], i);
	assert(best.nd != -1);
	printf("%d\n", best.nd);
	return 0;
}