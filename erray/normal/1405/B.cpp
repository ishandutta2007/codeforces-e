// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (sum < 0) {
        ans += -sum;
        sum = 0;
      }
    }
    cout << ans << '\n';
  }
}