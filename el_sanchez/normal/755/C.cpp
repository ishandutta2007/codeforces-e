#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 100500;

int n;
int nxt[MAXN];
set<int> diff;

int main() {
	
	while (cin >> n) {
		forn(i, n) {
			scanf("%d", &nxt[i]);
			nxt[i]--;
		}
		
		diff.clear();
		
		forn(i, n) {
			int v = i;
			forn(j, 5) {
				v = nxt[v];
			}
			
			int mv = v;
			forn(j, 5) {
				v = nxt[v];
				mv = min(mv, v);	
			}
			
			diff.insert(mv);
		}
		
		cout << diff.size() << '\n';
	}
		
	return 0;
}