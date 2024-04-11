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

const int N = 1005;

int l[N], r[N], a[N], used[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) cin >> l[i];
	forn(i, n) cin >> r[i];
	int cnt = 0;
	int cur = n;
	while(cnt != n) {
		vector<int> inds;
		forn(i, n) {
			if (used[i]) continue;
			if (!l[i] && !r[i]) {
				inds.pb(i);
				a[i] = cur;
				used[i] = true;
				cnt++;
			}
		}
		if (!sz(inds)) {
			cout << "NO\n";
			return 0;
		}
		for(int i : inds) {
			forn(j, i) {
				if (!used[j]) {
					r[j]--;
					if (r[j] < 0) {
						cout << "NO\n";
						return 0;
					}
				}
			}
			forab(j, i + 1, n) {
				if (!used[j]) {
					l[j]--;
					if (l[j] < 0) {
						cout << "NO\n";
						return 0;
					}
				}
			} 
		}
		cur--;
	}
	cout << "YES\n";
	forn(i, n) cout << a[i] << " ";
	cout << '\n';
	return 0;
}