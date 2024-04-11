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

  dotc() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int mx = a[0], mxDiff = 0;
    for (int i = 1; i < n; i++) {
      mxDiff = max(mx - a[i], mxDiff);
      mx = max(a[i], mx);
    }

    cout << (mxDiff ? (int)(log2(mxDiff) + 1) : 0) << '\n';
  }

  return 0;
}