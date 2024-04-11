#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<long double , ll> Ps;
typedef pair<ll, bool> Pb;

const ll INF = 1e18;
const ll fact_table = 3200008;
long double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
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
#define rep(i, n) for (ll i = 0; i < (n); i ++)

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= mod; b >>= 1;}(x *= a) %= mod; b--;} return x;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

/*
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
*/

bool multicase = false;

ll n, m, k, num, a, b, c, d, e, h, q, ans, sum;

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

ll x[200005], y[200005];
ll dp[10][10];
string s, t;
string u = "codeforces";


ll sx = 0, sy = 0;
vector<P> st;

void go(ll x, ll y){
    while(x != sx){
        if (x > sx){
            sx ++;
            st.pb(P(sx, sy));
        }
        if (x < sx){
            sx --;
            st.pb(P(sx, sy));
        }
    }
    while(y != sy){
        if (y > sy) {
            sy ++;
            st.pb(P(sx, sy));
        }
        if (y < sy) {
            sy --;
            st.pb(P(sx, sy));
        }
    }
    return;
}

void solve() {
    cin >> n;
    st.pb(P(0, 0));
    go(2 * n + 2, 0);
    bool s = false;
    ll v = 2 * n + 2;
    for(ll i=0;i<n+1;i++){
        ll u = s ? 2 : -2;
        s = !s;
        go(v, u);
        go(v-2, u);
        go(v-2, u/2);
        sy = 0;
        v -= 2;
    }
    assert(v == 0);
    p(st.size());
    for(auto u: st){
        pe(u.first);p(u.second);
    }
    return;
}

int main() {
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    // solve();
    return 0;
}