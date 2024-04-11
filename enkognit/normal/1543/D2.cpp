#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=998244353;
const ld E=1e-10;

ll K=125250;

ll n, m, k, a[1000001];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

ll rev(ll h)
{
    vector<ll> v;
    while (h)
    {
        v.pb(h%k);
        h/=k;
    }
    ll u=0;
    for (int i = v.size()-1; i > -1; i--)
    {
        u*=k;
        u+=(k-v[i])%k;
    }
    return u;
}

ll xr(ll x,ll y)
{
    vector<ll> v;
    //cout << " " << x << " " << y << "\n";
    while (x || y)
    {
        v.pb(x%k+y%k);
        x/=k;
        y/=k;
    }
    ll u=0;
    for (int i = v.size()-1; i > -1; i--)
        u=u*k+v[i]%k;
    return u;
}

void solve()
{
    cin >> n >> k;
    ll lst=0, r=0;
    for (ll i = 0; i < n; i++)
    {
        ll y=i;
        if (i%2) y=rev(y);
        cout << xr(y,lst) << "\n";
        lst=y;
        cin >> r;
        fflush(stdout);
        if (r==1) return;
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}