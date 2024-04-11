#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <unistd.h>
#include <stdlib.h>
#include <cassert>

using namespace std;
// using namespace atcoder;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 2e18;
const ll fact_table = 3200008;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/

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

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec readvec(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

/*
ll fact[fact_table + 5], rfact[fact_table + 5];

void c3_init() {
    fact[0] = rfact[0] = 1;
    for (ll i = 1; i <= fact_table; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table], mod - 2, mod);
    for (ll i = fact_table; i >= 1; i--) {
        rfact[i - 1] = rfact[i] * i;
        rfact[i - 1] %= mod;
    }
    return;
}
ll c3(ll n, ll r) {
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/

bool multicase = false;

struct SegmentTree {
    //SegmentTree seg( vector<ll>(l + 5, INF) );
private:
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while (n < sz) n *= 2;
        node.resize(2 * n - 1, -INF);
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = max(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(ll x, ll val) {
        //a[x]y()
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    ll getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        //[a,b)
        if (r < 0) r = n;
        if (r <= a || b <= l) return -INF;
        if (a <= l && r <= b) return node[k];

        ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
};

// ACL

ll n;
ll p[100];
ll q = 0;
ll x[100005], y[100005], z[100005];

ll add(ll n, ll m){
    x[q] = n, y[q] = m;
    z[q] = 1;
    q++;
    return n + m;
}

ll xx(ll n, ll m){
    x[q] = n, y[q] = m;
    z[q] = 0;
    q++;
    return n ^ m;
}

ll bit(ll n){
    for(int i=60;i>=0;i--){
        if ((n >> i) & 1ll) return i;
    }
    return -1;
}

void calc(ll n){
    ll shift = 0;
    for(int j=60;j>=0;j--){
        if (1ll << j & n) {
            shift = j;
            break;
        }
    }
    ll a = n;
    for(int i=0;i<shift;i++){
        a = add(a, a);
    }
    ll m = xx(a, n);
    ll k = add(a, n);
    ll s = xx(m, k);
    while(true){
        ll b1 = bit(m);
        ll b2 = bit(s);
        ll kk = s;
        if (b2 - b1 > 0) break;
        for(int i=0;i<b1 - b2;i++){
            kk = add(kk, kk);
        }
        m = xx(m, kk);
    }
    if (m == 1) return;
    calc(m);
}

void solve() {
    cin >> n;
    if (n % 4 == 3) {
        ll m = add(n, n);
        ll k = xx(m, n);
        n = k;
    }
    calc(n);
    p(q);
    for(int i=0;i<q;i++){
        if (z[i] == 1) {
            pe(x[i]);pe('+');p(y[i]);
        } else {
            pe(x[i]);pe('^');p(y[i]);

        }
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