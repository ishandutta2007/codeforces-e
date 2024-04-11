#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9+7;

int n;
int a[2010];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int ans = a[n] - a[1];
    for(int i=1; i<n; i++) {
        ans = max(ans, a[i] - a[i+1]);
        ans = max(ans, a[n] - a[i]);
        ans = max(ans, a[i+1] - a[1]);
    }
    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}