#include<iostream>
using std::cin;int N,K,A[1<<18],V[1<<18],i,r,M=998244353;main(){for(cin>>N;cin>>N>>K;printf("%d ",r)){for(i=N;i;V[A[r]=i--]=0)cin>>r;for(i=0;i<K;V[A[r]]=++i)cin>>r;V[0]=V[N+1]=K+1;for(r=i=1;i<=N;i++)if(V[i])r=r*((V[i-1]<V[i])+(V[i+1]<V[i]))%M;}}