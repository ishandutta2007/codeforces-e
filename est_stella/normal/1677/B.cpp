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

int n, m;
string s;
int r[1000010];
int c[1000010];
int ans[1000010];
int sum[1000010];

void solve() {
    cin >> n >> m;
    cin >> s;

    for(int i=0; i<n; i++) r[i] = 0;
    for(int i=0; i<m; i++) c[i] = 0;
    for(int i=0; i<n*m; i++) ans[i] = 0, sum[i+1] = 0;

    int cnt = 0;
    for(int i=0; i<n*m; i++) {
        if(c[i%m]) cnt--;
        if(s[i] == '1') c[i%m]++;
        if(c[i%m]) cnt++;
        
        ans[i] += cnt;
    }

    for(int i=0; i<n*m; i++) sum[i+1] = sum[i] + (s[i] == '1');
    
    for(int i=0; i<m; i++) {
        cnt = 0;
        for(int j=i+1; j<=n*m; j+=m) {
            if(sum[j] > sum[max(0, j-m)]) cnt++;
            ans[j-1] += cnt;
        }
    }

    for(int i=0; i<n*m; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}