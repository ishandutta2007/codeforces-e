// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

// modint
#define mod 998244353
struct modint{
	int x;
	modint(int o=0){x=o;}
	modint &operator = (int o){return x=o,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 300005
#define inf 0x3f3f3f3f

int n,k,fa[maxn],a[maxn];
vi e[maxn];
map<int,int>mp[maxn];

int dfs(int u,int k)
{
	if(!k)return 0;
	if(mp[u].count(k))return mp[u][k];
	int c=e[u].size(),res=a[u]*k,sum=0;
	if(!c)return mp[u][k]=res;
	if(k%c==0){
		for(auto v:e[u])res+=dfs(v,k/c);
		return mp[u][k]=res;
	}
	vector<int>o;
	for(auto v:e[u]){
		int v1=dfs(v,k/c);
		int v2=dfs(v,k/c+1);
		o.pb(v2-v1);
		sum+=v1;
	}
	res+=sum;
	int r=k%c;
	sort(o.begin(),o.end(),greater<int>());
	if(r)res+=accumulate(o.begin(),o.begin()+r,0ll);
	return mp[u][k]=res;
}

void work()
{
	n=read(),k=read();
	For(i,1,n)mp[i].clear(),e[i].clear();
	For(i,2,n)fa[i]=read(),e[fa[i]].pb(i);
	For(i,1,n)a[i]=read();
	cout<<dfs(1,k)<<"\n";
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}

/*
2
5 1
1 2 1 3
6 2 1 5 7
*/