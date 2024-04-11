#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define VI vector<int>
#define VLL vector<long long>

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    ll q=1;
    //cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        ll os=100005;
        ll a[2*os]={};
        REP(i,0,n)
        {
            ll t1,t2;
            cin>>t1>>t2;
            a[t2-t1+os]++;
        }
        ll cnt[2*os]={};
        VLL w[2*os];
        REP(i,0,n)
        {
            ll t;
            cin>>t;
            cnt[t+os]++;
            w[t+os].PB(i+1);
        }
        ll flag=0;
        REP(i,0,2*os)
        {
            if(cnt[i]!=a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO";
        }
        else
        {
            map<pair<ll,ll>,ll> dp;
            map<pair<ll,ll>,ll> mp;
            REP(i,0,os) 
            {
                sort(w[i].begin(),w[i].end());
                REP(j,0,w[i].size())
                {
                    mp.insert(MP(MP(j+os-i,j),w[i][j]));
                }
            }
            REP(i,os,2*os)
            {
                sort(w[i].begin(),w[i].end());
                REP(j,0,w[i].size())
                {
                    mp.insert(MP(MP(j,j+i-os),w[i][j]));
                }
            }
            ll ansa[n];
            ll ansb[n];
            REP(i,0,os)
            {
                if(mp.count(MP(i,0))==0) break;
                REP(j,0,os)
                {
                    if(mp.count(MP(i,j))==0) break;
                    dp.insert(MP(MP(i,j),mp[MP(i,j)]));
                    if(i!=0) dp[MP(i,j)]=max(dp[MP(i,j)],dp[MP(i-1,j)]);
                    if(j!=0) dp[MP(i,j)]=max(dp[MP(i,j)],dp[MP(i,j-1)]);
                    if(dp[MP(i,j)]!=mp[MP(i,j)])
                    {
                        cout<<"NO";
                        return 0;
                    }
                    ansa[mp[MP(i,j)]-1]=i;
                    ansb[mp[MP(i,j)]-1]=j;
                }
            }
            cout<<"YES\n";
            REP(i,0,n)
            {
                cout<<ansa[i]<<' '<<ansb[i]<<'\n';
            }
        }
    }

    return 0;
}