#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, sm, a[200005], kl[100005];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

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

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) kl[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        kl[a[i]%m]++;
    }
    ll ans=0;
    if (kl[0]) ans++;
    for (ll i = 1; i < m/2+m%2; i++)
        if (kl[i]+kl[m-i]>0)
        {
            ll p=min(kl[i], kl[m-i]);
            kl[i]=max(0ll, kl[i]-p-1);
            kl[m-i]=max(0ll, kl[m-i]-p-1);
            ans+=kl[i]+kl[m-i]+1;
            //cout << " " << kl[i]+kl[m-i] << "\n";
        }
    if (m%2==0)
    {
        if (kl[m/2]) ans++;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
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