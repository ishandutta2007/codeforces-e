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
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n; cin >> n;
  map<pair<int, int>, int> coords;
  map<int, int> hori, vert;
  while (n--) {
    int x, y; cin >> x >> y;
    hori[x]++;
    vert[y]++;
    coords[{x, y}]++;
  }

  ll cnt = 0;
  for (auto& i : hori) {
    cnt += (ll)i.se * (i.se - 1) / 2;
  }
  for (auto& i : vert) {
    cnt += (ll)i.se * (i.se - 1) / 2;
  }
  for (auto& i : coords) {
    cnt -= (ll)i.se * (i.se - 1) / 2;
  }

  cout << cnt;

  return 0;
}