#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);
void Miden(ll **p1,ll n);
void Mmult(ll **p1,ll **p2,ll **ans,ll x,ll y,ll z,ll m);
void Mpow(ll **p1,ll **ans,ll n,ll y,ll m);


ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}

ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}

ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}

void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}

void pairsortll(ll a[],ll b[],ll n)
{
    pair<ll,ll> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}

ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}

void Miden(ll **p1,ll n)
{
    ll (*x)[n]=(ll(*)[n]) p1;
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            x[i][j]=0;
        }
        x[i][i]=1;
    }
    return;
}

void Mmult(ll **p1,ll **p2,ll **ans,ll x,ll y,ll z,ll m)
{
    ll (*a)[y]=(ll (*)[y])p1;
    ll (*b)[z]=(ll (*)[z])p2;
    ll (*c)[z]=(ll (*)[z])ans;
    REP(i,0,x)
    {
        REP(j,0,z)
        {
            c[i][j]=0;
            REP(k,0,y)
            {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=m;
            }
        }
    }
    return;
}

void Mpow(ll **p1,ll **ans,ll n,ll y,ll m)
{
    if(y==0)
    {
        Miden(ans,n);
        return;
    }
    ll t[n][n];
    Mpow(p1,(ll **)t,n,y/2,m);
    ll z[n][n];
    Mmult((ll **)t,(ll **)t,(ll **)z,n,n,n,m);
    if(y%2)
    {
        Mmult((ll **)z,p1,ans,n,n,n,m);
    }
    else
    {
        Miden((ll **)t,n);
        Mmult((ll **)z,(ll **)t,ans,n,n,n,m);
    }
    return;
}

static ll ad[2005][2005];
static ll rn[2005];
static ll sz[2005];
static pll cs[2005];
set<ll> ps;
set<pll> cn;

ll fn(ll x)
{
    if(rn[x]==x) return x;
    else return rn[x]=fn(rn[x]);
}

void un(ll x,ll y)
{
    ll x0=fn(x);
    ll y0=fn(y);
    if(x0==y0) return;
    else if(ad[x][y]>max(cs[x0].F,cs[y0].F)) return;
    if(sz[x0]<sz[y0]) 
    {
        swap(x0,y0);
        swap(x,y);
    }
    sz[x0]+=sz[y0];
    rn[y0]=x0;
    cn.insert(MP(x,y));
    if(cs[x0].F>cs[y0].F)
    {
        ps.erase(ps.find(cs[x0].S));
        cs[x0]=cs[y0];
    }
    else
    {
        ps.erase(ps.find(cs[y0].S));
    }
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    ll ntc=1;
    //cin>>ntc;
    REP(tc,1,ntc+1)
    {
        //cout<<"Case #"<<tc<<": ";

        ll n;
        cin>>n;
        ll x[n],y[n],c[n],k[n];
        REP(i,0,n)
        {
            ll t1,t2;
            cin>>t1>>t2;
            x[i]=t1;
            y[i]=t2;
        }
        REP(i,0,n)
        {
            ll t;
            cin>>t;
            c[i]=t;
        }
        REP(i,0,n)
        {
            ll t;
            cin>>t;
            k[i]=t;
        }
        vector<tuple<ll,ll,ll>> v;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                ad[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
                v.PB(MT(ad[i][j],i,j));
            }
        }
        sort(v.begin(),v.end());
        REP(i,0,n)
        {
            rn[i]=i;
            sz[i]=1;
            cs[i]=MP(c[i],i);
            ps.insert(i);
        }
        REP(i,0,v.size())
        {
            un(G(1,v[i]),G(2,v[i]));
        }
        ll ans=0;
        for(auto it:ps)
        {
            ans+=c[it];
        }
        for(auto it:cn)
        {
            ans+=ad[it.F][it.S];
        }
        cout<<ans<<'\n';
        cout<<ps.size()<<'\n';
        for(auto it:ps)
        {
            cout<<it+1<<' ';
        }
        cout<<'\n'<<cn.size()<<'\n';
        for(auto it:cn)
        {
            cout<<it.F+1<<' '<<it.S+1<<'\n';
        }
    }

    return 0;
}