#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 1200008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//,,,

#define endl "\n"
#ifdef ENJAPMA
    #undef endl
#endif
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
const ll mod = 998244353ll;
// const ll mod = 2000000011;
  
ll mypow(ll number1,ll number2, ll mod){
    if(number2 == 0){
        return 1ll;
    }else{
        ll number3 = mypow(number1,number2 / 2, mod);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
void YES(bool condition){
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
 

ll fact[fact_table + 5],rfact[fact_table + 5]; 
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}


bool multicase = false;

ll n,m,num,a,b,c,d,e,h,q;
ll w, k, l, r;
ll x[500005], y[500005], z[500005];
bool used[500005];
string s;
vector<P> prime;

vector<ll> anss1, anss2;

vector<ll> vx, vy;

vector<ll> calc(ll value){
    vector<ll> v;
    for(ll i=0;i<prime.size();i++){
        ll cnt = 0;
        while(value % prime[i].first == 0){
            value /= prime[i].first;
            cnt ++;
        }
        v.pb(cnt);
    }
    return v;
}

void solve(){
    cin >> d;
    if(d == 1){
        cin >> q;
        for(ll i=0;i<q;i++){
            cin >> a >> b;
            p(1);
        }
        return;
    }
    prime.clear();
    for(ll i=2;i*i<=d;i++){
        ll cnt = 0;
        while(d % i == 0){
            d /= i;
            cnt ++;
        }
        if(cnt > 0){
            prime.pb(P(i, cnt));
        }
    }
    if(d > 1){
        prime.pb(P(d, 1));
    }
    ll size = prime.size();
    cin >> q;
    for(ll i=0;i<q;i++){
        cin >> x[i] >> y[i];
        vx.clear(); vy.clear();
        vx = calc(x[i]);
        vy = calc(y[i]);
        ll sum1 = 0, sum2 = 0;
        anss1.clear(); anss2.clear();
        for(ll i=0;i<size;i++){
            if(vx[i] - vy[i] > 0){
                anss1.pb(vx[i] - vy[i]);
                sum1 += vx[i] - vy[i];
            }else{
                anss2.pb(vy[i] - vx[i]);
                sum2 += vy[i] - vx[i];
            }
        }
        ll ans = fact[sum1] * fact[sum2];
        ans %= mod;
        for(ll j=0;j<anss1.size();j++){
            ans *= rfact[anss1[j]];
            ans %= mod;
        }
        for(ll j=0;j<anss2.size();j++){
            ans *= rfact[anss2[j]];
            ans %= mod;
        }
        p(ans);
    }    
    return ;
}

int main(){
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    c3_init();
    ll q;
    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
    }
    
    // solve();
    return 0;

}