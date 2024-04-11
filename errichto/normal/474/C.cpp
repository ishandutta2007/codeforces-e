#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
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

struct P {
	int x, y;
	P(int x = 0, int y = 0) : x(x), y(y) {}
	P operator + (const P & b) const { return P(x+b.x, y+b.y); }
	P operator - (const P & b) const { return P(x-b.x, y-b.y); }
	P & operator += (const P & b) { return *this = *this + b; }
	P & operator -= (const P & b) { return *this = *this - b; }
	ll operator * (const P & b) const { return (ll)x*b.y - (ll)y*b.x; }
	ll dotProduct(const P & b) const { return (ll)x*b.x + (ll)y*b.y; }
	void wypisz() { printf("(%d, %d), ", x, y); }
	void wczytaj() { scanf("%d%d", &x, &y); }
	bool prawy() const { return x > 0 || (!x && y > 0); }
	bool lewy() const { return x < 0 || (!x && y < 0); }
	bool operator < (const P & b) const { return *this * b < 0; }
	bool operator == (const P & b) const { return x == b.x && y == b.y; }
	ld norm() { return sqrt((ll) x * x + (ll) y * y); }
};

bool cmp_lewoprawo(const P & a, const P & b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

bool cmp_okrag(const P & a, const P & b) { return a.prawy() != b.prawy() ? a.prawy() : a * b < 0; }

vector<P> hull(vector<P> w) {
	// http://www.spoj.com/problems/GARDENHU/
	// http://codeforces.com/problemset/problem/166/B - razem z brzegami
	// http://www.spoj.com/problems/BSHEEP/ - wszystko brzegowe
	sort(w.begin(), w.end(), cmp_lewoprawo);
	w.resize(unique(w.begin(), w.end()) - w.begin());
	vector<P> res;
	int L = 0;
	REP(_, 2) {
		for(auto & C : w) {
			while((int) res.size() >= L + 2) {
				P A = res[(int) res.size() - 2];
				P B = res.back();
				if((C-A) * (B-A) > 0) break;
				res.pop_back();
			}
			res.pb(C);
		}
		res.pop_back();
		reverse(w.begin(), w.end());
		L = (int) res.size();
	}
	return res;
}

bool isSquare(P a, P b, P c, P d) {
	if(a == b) return false;
	REP(_, 2) {
		// a, b sasiaduja?
		
		P vec = b - a;
		vec = P(vec.y, -vec.x);
		REP(__, 2) {
			if(c == a + vec && d == b + vec) return true;
			if(d == a + vec && c == b + vec) return true;
			vec = P() - vec;
		}
		
		swap(a, c);
	}
	return false;
}

P p[4][4];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int z;
	scanf("%d", &z);
	while(z--) {
		REP(i, 4) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			p[i][0] = P(a,b);
			RI(j, 3) {
				auto vec = p[i][j-1] - P(c,d);
				p[i][j] = P(c,d) + P(-vec.y, vec.x);
			}
		}
		int res = inf;
		REP(a, 4) REP(b, 4) REP(c, 4) REP(d, 4)
			if(isSquare(p[0][a], p[1][b], p[2][c], p[3][d]))
				mini(res, a + b + c + d);
		if(res == inf) res = -1;
		printf("%d\n", res);
	}
	
	return 0;
}