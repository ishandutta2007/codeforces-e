#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n;
vector<pair<int, int> > lft, rght;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, a;
        scanf("%d%d", &x, &a);
        if (x < 0) {
            lft.pb(mp(x, a));
        } else {
            rght.pb(mp(x, a));
        }
    }
    sort(all(lft));
    reverse(all(lft));
    sort(all(rght));
    int l = min(lft.size(), rght.size());
    int sum = 0;
    for (int i = 0; i < l; i++) {
        sum += lft[i].sc;
        sum += rght[i].sc;
    }
    int ans = sum;
    if (lft.size() > l) {
        ans = max(ans, sum + lft[l].sc);
    }
    if (rght.size() > l) {
        ans = max(ans, sum + rght[l].sc);
    }
    cout << ans << endl;
    return 0;
}