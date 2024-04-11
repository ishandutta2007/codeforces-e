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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, mx, a[1000005], b[1000005], T;

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

#define dies_from_cringe exit(0)

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<ll> v;
    ll o=0;
    for (int i = 1; i <= n; i++) v.pb(-a[i]), v.pb(b[i]), o+=b[i]-a[i];;
    if (o<0) {cout << "NO\n";return;}
    vector<ll> pr, sf, pr2;
    ll sm=0;
    for (int i = 0; i < v.size(); i++)
    {
        sm+=v[i];
        if (i%2) pr.pb(sm); else pr2.pb(sm);
    }
    sm=0;
    for (int i = v.size()-1; i > -1; i--)
    {
        sm+=v[i];
        if ((v.size()-i)%2) sf.pb(sm);
    }
    ll mx=-1e18;
    for (int i = 0; i < n; i++)
    {
        mx=max(mx,pr2[i]);
        //cout << pr[i] << " " << mn << "\n";
        if (pr[i]-mx<0) {cout << "NO\n";return;}
    }
    set<pair<ll,int> > s;
    for (int i = 0; i < n; i++)
    {
        s.insert(mp(sf[i], i));
    }
    for (int i = 0; i < n; i++)
    {
        s.erase(mp(sf[n-i], n-i));
        if ((*s.begin()).fi+pr[i]<0) {cout << "NO\n";return;}
    }
    cout << "YES\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
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
1
3 3
10 1 2
5 1 1
*/