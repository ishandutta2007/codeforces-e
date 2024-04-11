#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

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
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};

#define maxn 200005
#define inf 0x3f3f3f3f

int n,m,b[233][233],k;
pii a[233*233];bool vis[233*233];
int ans[233][233];
void work()
{
	n=read(),m=read();
	For(i,1,n)For(j,1,m)b[i][j]=read();
	int res=0; k=0; 
	For(i,1,n)For(j,1,m)a[++k]=mkp(b[i][j],i),vis[k]=0;
	sort(a+1,a+k+1);
	int now=0;
	For(i,1,k){
		if(vis[i])continue;
		vis[i]=1; res+=a[i].fi;
		++now,ans[a[i].se][now]=a[i].fi;
//		cout<<i<<endl;
		For(j,1,n)
			if(j!=a[i].se){
				Rep(x,k,1)
					if(!vis[x] && a[x].se==j){
						vis[x]=1;
						ans[j][now]=a[x].fi;
						break;
					}
			}
	}
	For(i,1,n)For(j,1,m)cout<<ans[i][j]<<" \n"[j==m];
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}