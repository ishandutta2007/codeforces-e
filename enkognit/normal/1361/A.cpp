#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

string ans;
ll n, m, k, h, T, TT, lst, nm=0, a[1000001];
vector<ll> c[1000001];

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

bool comp(ll x,ll y)
{
    return a[x]<a[y];
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
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    for (int i = 1; i <= n; i++)
    {
        sort(all(c[i]), comp);
        ll o=0;
        for (int j = 0; j < c[i].size(); j++)
        {
            //cout << " " << c[i][j] << " " << a[c[i][j]] << "\n";
            if (a[c[i][j]]>a[i]) break;
            if (a[c[i][j]]>o+1)
            {
                cout << "-1\n";
                exit(0);
            }
            o=a[c[i][j]];
        }
        //cout << i << " " << o << "\n";
        if (o+1!=a[i]) {cout << "-1\n";exit(0);}
    }
    sort(all(v));
    for (int i = 0 ;i < v.size(); i++) cout << v[i].se << " ";
    cout << "\n";
    return 0;
}

/*

*/