#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, it, i, p, k, T, j, a[2000001], B, C, y, kol;
vector <ll> c[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);
        vector <ll> v;
        v.pb(a[0]);
        for (int i = 1; i < n; i++) if (a[i]!=a[i-1]) v.pb(a[i]);
        ll p=0, ans=0;

        for (int i = v.size()-1; i > -1; i--)
        {
            if (v[i]>p) ans++, p+=r;
        }
        cout << ans << "\n";
    }
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/