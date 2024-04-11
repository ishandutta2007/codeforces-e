#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
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

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, p, T, dp[505][505];
pll a[10001];
bool tt[1001];

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

void solve()
{
    cin >> n >> k;
    bool t=0;
    pll o=mp(0,0);
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j]=-1e18;
    dp[1][0]=0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            if (dp[i][j]!=-1e18)
        {
            //cout << i << " " << j << " " << dp[i][j] << "\n";
            dp[i+1][(j+a[i].fi)%k]=max(dp[i+1][(j+a[i].fi)%k], dp[i][j]+(j+a[i].fi)/k*k+a[i].se);
            ll aa=j, bb=dp[i][j]%k;
            if (a[i].fi+a[i].se>=k)
            for (int u = 0; u <= min(a[i].fi,k); u++)
            {
                ll k1=a[i].se-(k-u);
                if (k1<0) continue;
                dp[i+1][(j+(a[i].fi-u))%k]=max(dp[i+1][(j+(a[i].fi-u))%k], dp[i][j]+k+k1+(j+(a[i].fi-u))/k*k);
            }
        }
    ans=0;
    for (int j = 0; j < k; j++)
    {
        ans=max(ans, dp[n+1][j]/k);
//cout << j << " " << dp[n+1][j] << "\n";
    }
    cout << ans << "\n";
    return;
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
    //cin >> t;
    while (t--)
    {
        //cout << t << "\n";
        solve();
    }
    return 0;
}
/*
dp[]

*/