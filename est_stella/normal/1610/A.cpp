#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n == 1 && m == 1) cout << "0\n";
        else if(n == 1 || m == 1) cout << "1\n";
        else cout << "2\n";
    }
}