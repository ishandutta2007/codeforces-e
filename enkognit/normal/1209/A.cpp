#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

ll n, m, i, n1, p, n2, k, j, y, kol=1,  a[200001];
string s, d;
vector <ll> v, c[300001];
bool tt[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll p=0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        if (!tt[a[i]])
        {
            p++;
            ll z=a[i];
            while (z<=100) tt[z]=1, z+=a[i];
        }
    }
    cout << p;
    return 0;
}