#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans=1, N, kl[5001], dp[5001], a[5001];
vector<ll> c[100001];
vector<pll> v;

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

void solve()
{
    cin >> n >> k;
    ll kl=0;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        bool t=1;
        for (int j = 0; j < n; j++)
            if (abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se)>k)
            {
                //cout << i << " " << j
                t=0;
                break;
            }
        if (t)
        {
            cout << "1\n";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/