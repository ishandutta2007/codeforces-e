#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, t, j, sum, kol=0, a[1000001], d[1000001];
pll b[1000001];
string s;
vector <pll> v;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int,bool> w;
        vector <ll> v;
        w[0]=1;
        w[1]=1;
        v.pb(0);
        v.pb(1);
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (!w[n/i]) v.pb(n/i),w[n/i]=1;
            if (!w[i]) v.pb(i),w[i]=1;
        }
        sort(v.begin(),v.end());
        cout << v.size() << "\n";
        for (int j = 0; j < v.size(); j++) cout << v[j] << " ";
        cout << "\n";
    }

    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/