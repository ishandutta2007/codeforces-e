#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, ans, r, a[500001], T, o, an=0, b[101];
vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ll p=min(min(x,y),z);
        x-=p;
        y-=p;
        z-=p;
        ll o=min(x,y);
        cout << p+min(o,(x+y)/3) << "\n";
    }
    return 0;
}
/*
8 7
1 1 30 5 5 1 1 1
1 2
2 3
2 4
4 5
2 6
6 7
6 8
2
*/