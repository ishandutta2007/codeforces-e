#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1.2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(cll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
} 
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
cll IO_res=IO(),T=1;
bool p1;
aN f,pre;
int to[N][26],flag[11],kf[11];
char s[N];
bool p2;
void calc(){
    cll n=mygets(s+1),m=readll();
    ll j=0;
    to[0][s[1]-97]=to[1][s[1]-97]=1;
    rep(i,2,n){
        to[i-1][s[i]-97]=i;
        while(j&&s[i]!=s[j+1])j=pre[j];
        if(s[i]==s[j+1])j++;
        pre[i]=j;
        memcpy(to[i],to[j],sizeof to[i]);
    }
    rep(i,1,10)flag[i]=1;
    rep(i,1,10)rep(j,1,n)flag[i]&=s[j]==s[(j-1)%i+1];
    //rep(i,2,n)rep(j,0,25)to[i][j]=s[i]==j?:;
    //rep(i,1,n)writell(pre[i],10);
    memcpy(kf,flag,sizeof kf);
    rep(i,1,m){
        memcpy(flag,kf,sizeof kf);
        char*const t=s+n;
        cll m=mygets(t+1);
        ll now=n;
        rep(j,1,m){
            now=to[now][t[j]-97];
            ll minflag=mod;
            rep(k,1,10){
                flag[k]&=t[j]==s[(n+j-1)%k+1];
                if(flag[k])minflag=std::min(minflag,(ll)k);
            }
            //printf("%lld %lld\n",now,minflag);
            writell(std::max(now,n+j-minflag),j==m?10:32);
        }
    } 
}
int main(){
    fprintf(stderr,"%fMiB\n",(&p2-&p1)/1048576.0);
    rep(i,1,T)calc();
    return 0;
}
/*
1
2
0 1
0 1
*/