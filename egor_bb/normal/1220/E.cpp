#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 2e5 + 100;

int w[N], used[N], canup[N];
ll ans = 0, maxPath[N];
vector<int> g[N];

void dfs(int v, int from = -1) {
	used[v] = 1;
	maxPath[v] = w[v];
	for (int to : g[v]) {
		if (used[to] && to != from) {
			canup[v] = 1;
		} else if (!used[to]) {
			dfs(to, v);
			if (canup[to]) canup[v] = 1;
			maxPath[v] = max(maxPath[v], maxPath[to] + w[v]);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n) {
		cin >> w[i];
	}
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	int s;
	cin >> s;
	s--;
	dfs(s);
	forn(i, n) {
		if (canup[i] == 0) {
			ans = max(ans, maxPath[i]);
		}
	}
	forn(i, n) {
		if (canup[i]) {
			ans += w[i];
		}
	}
	cout << ans << '\n';
	return 0;
}