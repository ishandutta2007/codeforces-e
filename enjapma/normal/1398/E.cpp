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
struct Timer {
    int64_t start;
    const int64_t CYCLES_PER_SEC = 2800000000;
    Timer() { reset(); }
    void reset() { start = getCycle(); }
    inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
    inline int64_t getCycle() {
        uint32_t low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((int64_t)low) | ((int64_t)high << 32);
    }
};


bool multicase = false;

ll n, m, k, w, num, a, b, c, d, e, h, q, ans, sum, l;

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

ll dp[205][205][205];

void solve() {
    cin >> n;
    set<P> A, B;
    ll cnt = 0, allsum = 0, sum = 0;
    for(int i=0;i<n;i++){
        ll type, value;
        cin >> type >> value;
        allsum += value;
        if (type == 0 && value > 0) {
            // insert A
            B.insert(P(value, type));
            P mini = *begin(B);
            B.erase(mini);
            A.insert(mini);

            if (mini.second == 1) cnt --;
            sum += value;
            sum -= mini.first;

        } else if (type == 0 && value < 0) {
            // delete A
            value *= -1;
            if (A.count(P(value, type))) {
                A.erase(P(value, type));
            } else {
                B.erase(P(value, type));
                P maxi = *rbegin(A);
                A.erase(maxi);
                B.insert(maxi);
                if (maxi.second == 1) cnt ++;
                sum -= value;
                sum += maxi.first;
            }
        } else if (type == 1 && value > 0) {
            // insert B
            A.insert(P(value, type));
            P maxi = *rbegin(A);
            A.erase(maxi);
            B.insert(maxi);

            if (maxi.second == 1) cnt ++;
            sum += maxi.first;

        } else {
            // delete B
            value *= -1;
            if (B.count(P(value, type))) {
                B.erase(P(value, type));
                cnt --;
                sum -= value;
            } else {
                A.erase(P(value, type));
                P mini = *begin(B);
                B.erase(mini);
                A.insert(mini);
                if (mini.second == 1) cnt --;
                sum -= mini.first;
            }
        }
        ll mysum;
        if (B.size() == cnt && cnt > 0) {
            // B
            if (A.size()) {
                mysum = sum - (*begin(B)).first + (*rbegin(A)).first;
            } else {
                mysum = sum - (*begin(B)).first;
            }
        } else {
            mysum = sum;
        }
        p(mysum + allsum);
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