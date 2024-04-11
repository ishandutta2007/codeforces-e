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

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

pll Egcd(ll,ll);
pll Egcd(ll x,ll y)
{
    if(x==0) return MP(0,1);
    pll t=Egcd(y%x,x);
    return MP(t.S-t.F*(y/x),t.F);
}

ll powM(ll x,ll y,ll m)
{
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
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

bool isprime(ll n)
{
    if(n<2)
        return false;
    for(ll x:{2,3,5,7,11,13,17,19,23,29,31,37})
    {
        if(n==x)
            return true;
        bool flag=true;
        ll r=1;
        ll t=1;
        while(r<=((n-1)>>__builtin_ctzll(n-1)))
        {
            if(r&((n-1)>>__builtin_ctzll(n-1)))
                t=((__int128)t*x)%n;
            x=((__int128)x*x)%n;
            r<<=1;
        }
        if(t==1||t==n-1)
            flag=false;
        for(r=0;r<__builtin_ctzll(n-1);r++)
        {
            t=((__int128)t*t)%n;
            if(t==n-1)
                flag=false;
        }
        if(flag)
            return false;
    }
    return true;
}

ll PrimRoot(ll p,ll x)
{
    //finds primitive root of prime p greater than x(If it doesnt exist, returns 0)
    V(ll) v;
    ll t=p-1;
    REP(i,2,t+1)
    {
        if(i*i>t) break;
        if(t%i==0)
        {
            v.PB((p-1)/i);
            while(t%i==0)
            {
                t/=i;
            }
        }
    }
    if(t>1) v.PB((p-1)/t);
    REP(i,x+1,p)
    {
        ll flag=0;
        REP(j,0,((ll)v.size()))
        {
            if(powM(i,v[j],p)==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return i;
        }
    }

    return 0;
}

void fft(V(ll) &a,ll n,bool invert,ll m,ll x)
{
    REP(i,0,n)
    {
        ll y=0;
        REP(j,0,__builtin_ctzll(n))
        {
            if((1LL<<j)&i)
            {
                y|=(1LL<<(__builtin_ctzll(n)-j-1));
            }
        }
        if(y>i)
        {
            swap(a[i],a[y]);
        }
    }
    if(invert) x=modI(x,m);
    REP(s,1,__builtin_ctzll(n)+1)
    {
        ll y=powM(x,(n/(1LL<<s)),m);
        REP(j,0,(n/(1LL<<s)))
        {
            ll r=1;
            REP(i,0,(1LL<<(s-1)))
            {
                ll u=a[i+j*(1LL<<s)];
                ll v=(r*a[i+j*(1LL<<s)+(1LL<<(s-1))])%m;
                a[i+j*(1LL<<s)]=u+v;
                if(a[i+j*(1LL<<s)]>m) a[i+j*(1LL<<s)]-=m;
                a[i+j*(1LL<<s)+(1LL<<(s-1))]=u-v;
                if(a[i+j*(1LL<<s)+(1LL<<(s-1))]<0) a[i+j*(1LL<<s)+(1LL<<(s-1))]+=m;
                r*=y;
                r%=m;
            }
        }
    }
    if(invert)
    {
        ll invn=modI(n,m);
        REP(i,0,n)
        {
            a[i]=(a[i]*invn)%m;
        }
    }
    return;
}

void PolyMult(V(ll) &a,V(ll) &b,V(ll) &v,ll m,ll x)
{
    ll n=1;
    while(n<((ll)a.size())+((ll)b.size()))
    { 
        n<<=1;
    }
    V(ll) fa(a.begin(),a.end());
    fa.resize(n,0);
    V(ll) fb(b.begin(),b.end());
    fb.resize(n,0);
    ll y=powM(x,(m-1)/n,m);
    fft(fa,n,false,m,y);
    fft(fb,n,false,m,y);
    v.resize(n,0);
    REP(i,0,n)
    {
        v[i]=((fa[i]*fb[i])%m);
    }
    fft(v,n,true,m,y);
    return;
}

ll fn(ll x,ll rn[])
{
    if(x==rn[x])
        return x;
    else
        return rn[x]=fn(rn[x],rn);
}

bool un(ll x,ll y,ll rn[],ll sz[])
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y)
        return false;
    if(sz[x]<sz[y])
        swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;
    return true;
}

void build(ll v,ll tl,ll tr,ll st[],ll lz[],bool f[],ll a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
        lz[v]=0LL;
        f[v]=false;
        return;
    }
    build((v<<1),tl,((tl+tr)>>1),st,lz,f,a);
    build((v<<1)|1,((tl+tr)>>1)+1,tr,st,lz,f,a);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    lz[v]=0LL;
    f[v]=false;
    return;
}

void push(ll v,ll tl,ll tr,ll st[],ll lz[],bool f[])
{
    if(f[v])
    {
        //operation
        st[(v<<1)]=lz[(v<<1)]=st[(v<<1)|1]=lz[(v<<1)|1]=0LL;
        f[(v<<1)]=f[(v<<1)|1]=true;
        f[v]=false;
    }
    //operation
    st[(v<<1)]+=lz[v]*(((tl+tr)>>1)-tl+1);
    //operation
    lz[(v<<1)]+=lz[v];
    //operation
    st[(v<<1)|1]+=lz[v]*(tr-((tl+tr)>>1));
    //operation
    lz[(v<<1)|1]+=lz[v];
    lz[v]=0LL;
    return;
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll val,bool set,ll st[],ll lz[],bool f[])
{
    if(l>r)
    {
        return;
    }
    if(l==tl&&tr==r)
    {
        if(set)
        {
            //operation
            st[v]=lz[v]=0LL;
            f[v]=true;
        }
        //operation
        st[v]+=val*(tr-tl+1);
        //operation
        lz[v]+=val;
        return;
    }
    push(v,tl,tr,st,lz,f);
    update((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),val,set,st,lz,f);
    update((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,val,set,st,lz,f);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    return;
}

ll query(ll v,ll tl,ll tr,ll l,ll r,ll st[],ll lz[],bool f[])
{
    if(l>r)
    {
        return 0LL;
    }
    if(l==tl&&tr==r)
    {
        return st[v];
    }
    push(v,tl,tr,st,lz,f);
    //operation
    return query((v<<1),tl,((tl+tr)>>1),l,min(r,((tl+tr)>>1)),st,lz,f)+query((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),r,st,lz,f);
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

        ll n,m,k,x,y,src=-1,dest=-1;
        cin>>n>>m>>k;
        V(pll) r[n];
        V(pll) c[m];
        V(pll) ad[7*k];
        REP(i,0,k)
        {
            cin>>x>>y;
            x--;y--;
            if(x==0&y==0)
            {
                src=i;
            }
            if(x==n-1&y==m-1)
            {
                dest=i;
            }
            r[x].PB(MP(y,i));
            c[y].PB(MP(x,i));
            REP(j1,0,7)
            {
                REP(j2,0,7)
                {
                    ad[i+j1*k].PB(MP(i+j2*k,1));
                    ad[i+j2*k].PB(MP(i+j1*k,1));
                }
                ad[i+j1*k].PB(MP(i,0));
            }
        }
        REP(i,0,n)
        {
            sort(r[i].begin(),r[i].end());
        }
        REP(i,0,m)
        {
            sort(c[i].begin(),c[i].end());
        }
        REP(i,0,n)
        {
            REP(j,1,((ll)r[i].size()))
            {
                if(r[i][j].F==r[i][j-1].F+1)
                {
                    ad[r[i][j].S].PB(MP(r[i][j-1].S,0));
                    ad[r[i][j-1].S].PB(MP(r[i][j].S,0));
                }
                REP(t1,1,4)
                {
                    ad[r[i][j].S+t1*k].PB(MP(r[i][0].S+t1*k,0));
                    ad[r[i][0].S+t1*k].PB(MP(r[i][j].S+t1*k,0));
                }
            }
        }
        REP(i,0,m)
        {
            REP(j,1,((ll)c[i].size()))
            {
                if(c[i][j].F==c[i][j-1].F+1)
                {
                    ad[c[i][j].S].PB(MP(c[i][j-1].S,0));
                    ad[c[i][j-1].S].PB(MP(c[i][j].S,0));
                }
                REP(t1,4,7)
                {
                    ad[c[i][j].S+t1*k].PB(MP(c[i][0].S+t1*k,0));
                    ad[c[i][0].S+t1*k].PB(MP(c[i][j].S+t1*k,0));
                }
            }
        }
        REP(i,1,n)
        {
            if(!(r[i].empty()||r[i-1].empty()))
            {
                ad[r[i-1][0].S+2*k].PB(MP(r[i][0].S+k,0));
                ad[r[i][0].S+k].PB(MP(r[i-1][0].S+2*k,0));
                ad[r[i-1][0].S+3*k].PB(MP(r[i][0].S+2*k,0));
                ad[r[i][0].S+2*k].PB(MP(r[i-1][0].S+3*k,0));
            }
        }
        REP(i,1,m)
        {
            if(!(c[i].empty()||c[i-1].empty()))
            {
                ad[c[i-1][0].S+5*k].PB(MP(c[i][0].S+4*k,0));
                ad[c[i][0].S+4*k].PB(MP(c[i-1][0].S+5*k,0));
                ad[c[i-1][0].S+6*k].PB(MP(c[i][0].S+5*k,0));
                ad[c[i][0].S+5*k].PB(MP(c[i-1][0].S+6*k,0));
            }
        }
        REP(i,2,n)
        {
            if(!(r[i].empty()||r[i-2].empty()))
            {
                ad[r[i-2][0].S+3*k].PB(MP(r[i][0].S+k,0));
                ad[r[i][0].S+k].PB(MP(r[i-2][0].S+3*k,0));
            }
        }
        REP(i,2,m)
        {
            if(!(c[i].empty()||c[i-2].empty()))
            {
                ad[c[i-2][0].S+6*k].PB(MP(c[i][0].S+4*k,0));
                ad[c[i][0].S+4*k].PB(MP(c[i-2][0].S+6*k,0));
            }
        }
        ll dis[7*k];
        REP(i,0,7*k)
        {
            dis[i]=(1LL<<60);
        }
        deque<pll> pr;
        pr.push_back(MP(0,src));
        while(!pr.empty())
        {
            pll t=pr.front();
            pr.pop_front();
            if(dis[t.S]==(1LL<<60))
            {
                dis[t.S]=t.F;
                for(auto it:ad[t.S])
                {
                    if(dis[it.F]==(1LL<<60))
                    {
                        if(it.S==0)
                            pr.push_front(MP(t.F,it.F));
                        else
                            pr.push_back(MP(t.F+1,it.F));
                    }
                }
            }
        }
        // REP(i,0,7)
        // {
        //     REP(j,0,k)
        //     {
        //         cout<<dis[j+i*k]<<' ';
        //     }
        //     cout<<'\n';
        // }
        ll ans=(1LL<<60);
        if(dest!=-1) 
        {
            ans=min(ans,dis[dest]);
        }
        if(n>=1&&!r[n-1].empty())
        {
            ans=min(ans,dis[r[n-1][((ll)r[n-1].size())-1].S+2*k]);
        }
        if(n>=2&&!r[n-2].empty())
        {
            ans=min(ans,dis[r[n-2][((ll)r[n-2].size())-1].S+3*k]);
        }
        if(m>=1&&!c[m-1].empty())
        {
            ans=min(ans,dis[c[m-1][((ll)c[m-1].size())-1].S+5*k]);
        }
        if(m>=2&&!c[m-2].empty())
        {
            ans=min(ans,dis[c[m-2][((ll)c[m-2].size())-1].S+6*k]);
        }
        if(ans!=(1LL<<60))
            cout<<ans;
        else
            cout<<-1;

        cout<<'\n';
    }

    return 0;
}