#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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

const ll MOD = 1e9+7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, TT, T, L, R, mx=0, ans, an[1000001], a[1000001], kl[1000001];
vector<ll> v;
bool tt[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{

    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

bool comp(pair<pll,ll> x,pair<pll,ll> y)
{
    return (x.fi.se<y.fi.se || x.fi.se==y.fi.se && x.fi.fi<y.fi.fi);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll p=sqrt(n);
    vector<pair<pll,ll> > v;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(mp(x,y),i));
    }
    sort(all(v));
    vector<pll> z;
    z.pb(mp(0,0));
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].fi.fi/p==v[i-1].fi.fi/p) z.back().se++; else z.pb(mp(i,i));
    }
    for (int i = 0; i < z.size(); i++)
    {
        sort(v.begin()+z[i].fi,v.begin()+z[i].se+1,comp);
        if (i%2) reverse(v.begin()+z[i].fi,v.begin()+z[i].se+1);
    }
    L=1, R=0;
    for (int i = 0; i < v.size(); i++)
    {
        ll l=v[i].fi.fi, r=v[i].fi.se;
        //cout << l << " " << r << "\n";
        while (l<L)
        {
            L--;
            ans-=kl[a[L]]*kl[a[L]]*a[L];
            kl[a[L]]++;
            ans+=kl[a[L]]*kl[a[L]]*a[L];
        }
        while (r>R)
        {
            R++;
            ans-=kl[a[R]]*kl[a[R]]*a[R];
            kl[a[R]]++;
            ans+=kl[a[R]]*kl[a[R]]*a[R];
        }
        while (l>L)
        {
            ans-=kl[a[L]]*kl[a[L]]*a[L];
            kl[a[L]]--;
            ans+=kl[a[L]]*kl[a[L]]*a[L];
            L++;
        }
        while (r<R)
        {
            ans-=kl[a[R]]*kl[a[R]]*a[R];
            kl[a[R]]--;
            ans+=kl[a[R]]*kl[a[R]]*a[R];
            R--;
        }
        an[v[i].se]=ans;
    }
    for (int i = 1; i <= m; i++) cout << an[i] << "\n";
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/