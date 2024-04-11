// #pragma GCC target("avx")  // CPU 
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
const int C_SIZE = 3100000;
const int UF_SIZE = 210000;
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
	int UF[UF_SIZE];
	void init_UF(int n){
		for(int i=0;i<n;i++)UF[i]=-1;
	}
	int FIND(int a){
		if(UF[a]<0)return a;
		return UF[a]=FIND(UF[a]);
	}
	void UNION(int a,int b){
		a=FIND(a);b=FIND(b);if(a==b)return;
		if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// 
int X[1100];
int Y[1100];

int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d%d",X+i,Y+i);
	for(int i=0;i<a;i++){
		X[i]+=1100000;
		Y[i]+=1100000;
	}
	int B=1;
	while(1){
		int L=0;
		int R=0;
		for(int i=0;i<a;i++){
			if((X[i]+Y[i])%(B*2)/B)L++;
			else R++;
		}
		if(L&&R){
			vector<int>ret;
			for(int i=0;i<a;i++){
				if((X[i]+Y[i])%(B*2)/B){
					ret.push_back(i+1);
				}
			}
			printf("%d\n",(int)ret.size());
			for(int i=0;i<ret.size();i++){
				if(i)printf(" ");
				printf("%d",ret[i]);
			}printf("\n");
			return 0;
		}
		L=R=0;
		for(int i=0;i<a;i++){
			if(X[i]%(B*2)/B)L++;
			else R++;
		}
		if(L&&R){
			vector<int>ret;
			for(int i=0;i<a;i++){
				if(X[i]%(B*2)/B){
					ret.push_back(i+1);
				}
			}
			printf("%d\n",(int)ret.size());
			for(int i=0;i<ret.size();i++){
				if(i)printf(" ");
				printf("%d",ret[i]);
			}printf("\n");
			return 0;
		}
		B*=2;
	}
}