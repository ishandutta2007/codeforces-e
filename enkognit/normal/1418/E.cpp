#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T;

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll a[1000001], fact[200001], infact[200001], pr[200001];

ll C(ll n,ll k)
{
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    cin >> n >> m;
    pr[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        pr[i]=(pr[i-1]+a[i])%MOD;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll l=0, r=n;
        while (l<r)
        {
            int w=(l+r+1)/2;
            if (a[w]<y) l=w; else r=w-1;
        }
        if (n-l<x) {cout << "0\n";continue;}
        ll ans=0;
        if (l<n) ans=(ans+pr[l]*(C(n, n-l+1)*fact[n-l]%MOD*fact[l-1]%MOD*(n-l+1-x)%MOD*infact[n]%MOD)%MOD)%MOD;
        ll o=(pr[n]-pr[l]);
        if (o<0) o+=MOD;
        ans=(ans+o*(C(n, n-l)*fact[n-l-1]%MOD*(n-l-x)%MOD*fact[l]%MOD*infact[n]%MOD)%MOD)%MOD;
        cout << ans << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 2e5; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/