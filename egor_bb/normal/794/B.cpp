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

const int N = 1e6;

ld ans[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, h;
	cin >> n >> h;
	ld s = (h * 1. / 2) / n;
	ld h1 = 0;
	cout.precision(20);
	forn(i, n - 1) {
		ld w = (ld)(h - h1) / h;
		ld l = 0, r = h - h1;
		forn(j, 500) {
			ld m = (l + r) / 2;
			ld w2 = (h - h1 - m) / h;
			ld s2 = (w + w2) * m / 2;
			if (s2 > s) {
				r = m;
			} else {
				l = m;
			}
		}
		h1 += l;
		ans[i] = h1;
	}
	fornr(i, n - 1) {
		cout << fixed << (dbl)h - (dbl)ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}