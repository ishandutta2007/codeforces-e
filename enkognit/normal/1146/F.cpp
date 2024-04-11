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

const ll MOD = 998244353;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, ans, p, T, dp[200001][2];
vector<ll> c[200001];

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

void dfs(int h,int p=-1)
{
    if (c[h].size()==0)
    {
        dp[h][0]=1;
        dp[h][1]=1;
        return;
    }
    ll p1=1, p2=1, p3=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],h);
            p1=(p1*((dp[c[h][i]][0]+dp[c[h][i]][1])%MOD))%MOD;
            p2=(p2*((dp[c[h][i]][1])%MOD))%MOD;
        }
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            p3=(p3+p2*binpow(dp[c[h][i]][1],MOD-2)%MOD*dp[c[h][i]][0]%MOD)%MOD;
        }
    p1-=p2;
    //cout << h << " " << c[h].size() << " ";
    //cout << p1 << " " << p2 << " " << p3 << "\n";
    if (p1<0) p1+=MOD;
    dp[h][0]=p1;
    dp[h][1]=(p2+p1-p3)%MOD;
    if (dp[h][1]<0) dp[h][1]+=MOD;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        c[x].pb(i);
    }
    dfs(1);
    cout << dp[1][1] << "\n";
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