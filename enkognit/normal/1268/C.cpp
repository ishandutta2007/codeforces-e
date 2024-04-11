#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, ans, TT, l, T, i, j, h, pp=0, pos[1000001];
ll a[2000001];
bool tt[2000001];
vector <ll> c[1000001], v;
ll d[10000001];

void update(ll h,ll l,ll r,ll x)
{
    if (l==r) {d[h]=1;return;}
    ll w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h]=d[h*2]+d[h*2+1];
}

ll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    ll w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

ll fnd(ll h,ll l,ll r,ll k)
{
    if (l==r) return l;
    ll w=(l+r)/2;
    if (d[h*2]>=k) return fnd(h*2,l,w,k); else return fnd(h*2+1,w+1,r,k-d[h*2]);
}

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];pos[a[i]]=i;}
    cout << "0 ";
    update(1,1,n,pos[1]);
    ll ans=0, kl=1;
    for (int i = 2; i <= n; i++)
    {
        ll u=0;
        if (i%2)
        {
            ll o=fnd(1,1,n,kl/2), p=fnd(1,1,n,kl/2+1);
            if (pos[i]<o) u=o-pos[i]-1-get(1,1,n,pos[i]+1,o-1); else
            if (pos[i]>p) u=pos[i]-p-1-get(1,1,n,p+1,pos[i]-1);
        }else
        {
            ll p=fnd(1,1,n,kl/2+1);
            if (pos[i]>p) u=pos[i]-p-1-get(1,1,n,p+1,pos[i]-1); else u=p-pos[i]-1-get(1,1,n,pos[i]+1,p-1);
        }
        update(1,1,n,pos[i]);
        ll p=get(1,1,n,pos[i]+1,n);
        ans+=p+u-min(p,kl-p);
        cout << ans << " ";
        kl++;
    }
    return 0;
}
/*
10

5 1 6 2 8 3 4 10 9 7

*/