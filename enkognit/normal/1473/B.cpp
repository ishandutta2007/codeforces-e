#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

const ll MOD=1000000007;

ll n, m, k, q, T;
ll a[500001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    string s, d;
    cin >> s;
    cin >> d;
    ll o1=s.size(), o2=d.size(), o=o1*o2/__gcd(o1, o2);
    string ss, dd;
    while (ss.size()<o) ss+=s;
    while (dd.size()<o) dd+=d;
    for (int i = 0 ;i < o; i++)
    {
        if (ss[i]!=dd[i])
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ss << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
11
CCCTTTTTTCC
3
1 11
4 9
1 6
*/