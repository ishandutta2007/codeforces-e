#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

int n, m, k, T, Z, a[10001], fr[10001], kl[1000001];
vector<pii> c[1000001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    return l;
}

vector<ll> v;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n*2; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n*2+1);
    //reverse(a+1,a+n*2+1);
    for (int j = 1; j < n*2; j++)
    {
        for (int i = 1; i < n*2; i++) if (i!=j) kl[a[i]]++;
        vector<pii> v;
        v.pb(mp(a[n*2], a[j]));
        ll lst=a[n*2];
        bool T=0;
        for (int i = n*2-1; i > 0; i--)
        {
            if (kl[a[i]] && i!=j)
            {
                kl[a[i]]--;
                if (!kl[lst-a[i]])
                {
                    T=1;
                    break;
                }else
                {
                    v.pb(mp(lst-a[i], a[i]));
                    kl[lst-a[i]]--;
                    lst=a[i];
                }
            }
        }
        for (int i = 1; i <= n*2; i++) kl[a[i]]=0;
        if (T) continue;
        cout << "YES\n";
        cout << a[n*2]+a[j] << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i].fi << " " << v[i].se << "\n";
        return;
    }
    cout << "NO\n";
    for (int i = 1; i <= n*2; i++) kl[a[i]]=0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("oddeven.in","r",stdin);
    //freopen("oddeven.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
15 6
xzxyyzxxzxyyzyx
a 2 10
a 15 4
q 3
a 12 2
q 14
q 2
*/