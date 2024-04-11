#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
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
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;

char sl[2][nax], res[nax];

int main() {
	int n, eq;
	scanf("%d%d", &n, &eq);
	eq = n - eq;
	scanf("%s%s", sl[0], sl[1]);
	res[n] = sl[0][n];
	REP(i, n) res[i] = 0;
	vi w;
	REP(i, n) if(sl[0][i] != sl[1][i]) {
		w.pb(i);
	}
	while(eq && sz(w) >= 2) {
		int a = w.back();
		w.pop_back();
		int b = w.back();
		w.pop_back();
		res[a] = sl[0][a];
		res[b] = sl[1][b];
		--eq;
	}
	REP(i, n) if(sl[0][i] == sl[1][i] && eq) {
		--eq;
		res[i] = sl[0][i];
	}
	if(eq) puts("-1");
	else {
		REP(i,n) if(res[i] == 0) {
			res[i] = 'a';
			while(res[i] == sl[0][i] || res[i] == sl[1][i])
				++res[i];
		}
		printf("%s\n", res);
	}
	return 0;
}