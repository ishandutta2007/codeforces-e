#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  ll w, m, k;
  cin >> w >> m >> k;
  w = w / k;

  ll d = 0;
  for (ll t = m; t; t /= 10, d++);

  ll l = m - 1, r = 1e17;
  while (l < r) {
    ll mi = (l + r + 1) / 2, cur = mi;
    ll sum = 0;
    ll d2 = 0, dn2 = 1;
    for (ll t = cur; t; t /= 10, d2++, dn2 *= 10);
    dn2 /= 10;

    while (d2 > d) {
      sum += d2 * (cur - dn2 + 1);
      cur = dn2 - 1;
      dn2 /= 10;
      d2--;
    }

    sum += d2 * (cur - m + 1);
    if (sum > w) r = mi - 1;
    else l = mi;
  }

  cout << l - m + 1;

  return 0;
}