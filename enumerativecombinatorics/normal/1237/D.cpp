// #pragma GCC target("avx2")  // CPU 
// #pragma GCC optimize("O3")  // CPU 
// #pragma GCC optimize("unroll-loops")  // 
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
#include<unordered_set>
#include<complex>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	long long Comb(int a,int b){
	 	if(a<b||b<0)return 0;
	 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
	}
	void init_C(int n){
		fact[0]=finv[0]=inv[1]=1;
		for(int i=2;i<n;i++){
			inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
		}
		for(int i=1;i<n;i++){
			fact[i]=fact[i-1]*i%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	long long pw(long long a,long long b){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return ret;
	}
	long long pw_mod(long long a,long long b,long long M){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%M;
			a=a*a%M;
			b/=2;
		}
		return ret;
	}
	int pw_mod_int(int a,int b,int M){
		if(a<0)return 0;
		if(b<0)return 0;
		int ret=1;
		while(b){
			if(b%2)ret=(long long)ret*a%M;
			a=(long long)a*a%M;
			b/=2;
		}
		return ret;
	}
	int ABS(int a){return max(a,-a);}
	long long ABS(long long a){return max(a,-a);}
	double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
}
// 
int p[310000];
pair<int,int>ev[110000];
int to[110000];
int segtree[524288];
int query(int a,int b,int c,int d,int e){
	if(d<a||b<c)return mod;
	if(c<=a&&b<=d)return segtree[e];
	return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
	a+=262144;
	while(a){
		segtree[a]=min(segtree[a],b);
		a/=2;
	}
}
int ans[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	for(int i=0;i<a;i++){
		p[i+a]=p[i];
		p[i+2*a]=p[i];
		ev[i]=make_pair(p[i],i);
	}
	std::sort(ev,ev+a);
	int at=0;
	set<int>S;
	S.insert(mod);
	for(int i=0;i<a;i++){
		while(at<a&&ev[at].first*2<ev[i].first){
			S.insert(ev[at].second);
			S.insert(ev[at].second+a);
			at++;
		}
		set<int>::iterator it=S.lower_bound(ev[i].second);
		to[ev[i].second]=(*it);
	}
	for(int i=0;i<524288;i++)segtree[i]=mod;
	for(int i=0;i<a;i++){
		// printf("%d\n",to[i]);
		update(i,to[i]);
		update(i+a,to[i]+a);	
	}
	for(int i=0;i<a;i++){
		int left=0;
		int right=2*a+1;
		while(left+1<right){
			int M=(left+right)/2;
			int val=query(0,262143,i,min(i+M-1,a*2-1),1);
			if(val<i+M){
				right=M;
			}else left=M;
		}
		if(left==2*a)ans[i]=-1;
		else ans[i]=left;
	}
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}