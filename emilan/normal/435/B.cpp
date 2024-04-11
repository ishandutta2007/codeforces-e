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

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  string a; int k; cin >> a >> k;
  for (int i = 0; i < sz(a); i++) {
    auto hi = max_element(a.begin() + i, a.begin() + min(i + k + 1, sz(a)));
    int dist = distance(a.begin() + i, hi);
    k -= dist;
    for (int j = i + dist; j > i; j--)
      swap(a[j - 1], a[j]);
  }

  cout << a;

  return 0;
}