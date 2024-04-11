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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 100500;

int n, k;
int a[MAXN];
ll ans;

int main() {
    
    
    while (cin >> n >> k) {
    ans = 0;        
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    ans = 0;
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[0];
        if (d % k != 0) {
            cout << -1 << '\n';
            return 0;
        }
        ans += d / k;
    }
    cout << ans << '\n';
    }
    
    return 0;
}