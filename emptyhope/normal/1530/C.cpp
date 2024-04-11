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

#define maxn 200005 
#define inf 0x3f3f3f3f
int n,m,s1,s2;
priority_queue<int,vector<int>,greater<int> >q1,q2;
priority_queue<int>q3; 
void work()
{
	s1=0,s2=0;
	while(q1.size())q1.pop(); while(q2.size())q2.pop();
	while(q3.size())q3.pop();
	n=read(),m=n;
	For(i,1,n){
		int x=read();
		s1+=x,q1.push(x);
	}
	For(i,1,m){
		int x=read();
		s2+=x,q2.push(x);
	}
	int res=0,c1=n,c2=m;
	For(i,1,c1/4)s1-=q1.top(),q1.pop();
	For(i,1,c2/4)s2-=q2.top(),q3.push(q2.top()),q2.pop();
	
	while(s1<s2){
		++res;
		++c1,++c2;
		q1.push(100),q2.push(0),s1+=100;
		if(c1%4==0) s1-=q1.top(),q1.pop();
		if(q3.size()){
			s2+=q3.top(); int t=q3.top(); q3.pop(); 
			q3.push(q2.top()) , q2.pop(); q2.push(t);
		}
		if(c2%4==0){
//			cout<<"c2 : "<<q2.top()<<endl;
			s2-=q2.top();
			q3.push(q2.top()),q2.pop();
		}
//		cout<<"s12 "<<s1<<" "<<s2<<endl;
	}
	cout<<res<<endl;
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}
/*
5
0 0 0 0 0
100 100 100 100 100
*/