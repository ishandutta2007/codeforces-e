#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, sf[100001], pr[100001];
pll  d[1000001];
string s;

void build(ll h,ll l,ll r)
{
    if (l==r)
    {
        d[h]=mp(pr[l]+sf[r],l);
        return;
    }
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    if (d[h*2+1].fi>=d[h*2].fi) d[h]=d[h*2+1]; else d[h]=d[h*2];
}

pll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return mp(0,0);
    if (l==x && r==y)return d[h];
    ll w=(l+r)/2;
    pll o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    if (o2.fi>=o1.fi) return o2; else return o1;
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    s=' '+s;
    ll n=s.size()-1;
    for (int i = 1; i <= n; i++) pr[i]=pr[i-1]+(s[i]=='0');
    for (int i = n; i > 0; i--) sf[i]=sf[i+1]+(s[i]=='1');
    build(1,1,n);
    vector <pll> v={};
    for (int i = 1; i <= n; i++)
    {
        ll pos=get(1,1,n,i,n).se;

        if (pos>i) v.pb(mp(i,pos-1));
    }
    ll lst=1;
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i].fi << " " << v[i].se << "\n";
        for (int j = lst; j < v[i].fi; j++) s[j]='0';
        lst=v[i].se+1;
    }
    for (int j = lst; j <= n; j++) s[j]='0';
    s.erase(0,1);
    cout << s;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/