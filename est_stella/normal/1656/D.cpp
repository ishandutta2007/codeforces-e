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
const ll Mod = 998244353;

void solve() {
    ll n;
    cin >> n;
    n <<= 1;
    ll k = 1;
    while(n % (2*k) == 0) {
        k <<= 1;
    }

    if(n == k) {
        cout << "-1\n";
        return;
    }

    k = min(k, n/k);
    cout << k << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}