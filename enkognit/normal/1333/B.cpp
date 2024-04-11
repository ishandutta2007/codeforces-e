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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;
const ld PI=3.141592653589793238462;
const ll MOD = 1e9+7;//998244353;

mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, T, Q;
pll pr[1000001];
ll a[1000001], b[1000001];
vector<ll> v;

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    pll o=mp(0,0);
    for (int i = 1; i <= n; i++)
    {
        pr[i]=o;
        if (a[i]==-1) o.fi=1;
        if (a[i]==1) o.se=1;
    }
    bool t=1;
    for (int i = n; i > 0; i--)
    {
        if (a[i]>b[i])
        {
            if (!pr[i].fi) t=0;
        }
        if (a[i]<b[i])
        {
            if (!pr[i].se) t=0;
        }
    }
    if (t) cout << "YES\n"; else cout << "NO\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("function.in","r",stdin);
    //freopen("function.out","w",stdout);
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
6 8
1 2 3
1 3 3
2 4 2
2 5 2
3 4 2
3 5 2
5 6 3
4 6 3
*/