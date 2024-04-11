#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    int n, k;
    cin >> n >> k;

    vi a(n), r;
    rep(i, n) {
      cin >> a[i];
      if (a[i] & 1) {
        r.pb(i);
      }
    }

    r.pb(n);
    r.erase(r.begin());

    if (sz(r) < k || (sz(r) & 1) != (k & 1)) cout << "NO\n";
    else {
      cout << "YES\n";
      while (sz(r) > k) r.erase(r.begin(), r.begin() + 2);
      for (int i : r) cout << i << ' ';
      cout << '\n';
    }
  }

  return 0;
}