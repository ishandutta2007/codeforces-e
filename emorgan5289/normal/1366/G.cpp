#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() const { return s; }
    
    // insert x into the set with multiplicity k
    void insert(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) const {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    int count(int x) const {
        int y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

const int N = 10005;
int p[N], dp[N][N];

fenwick_multiset<N> f;
multiset<int> b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    s += '$', t += '$';
    int n = s.size(), m = t.size();
    fill(p, p+N, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (!b.empty()) {
                p[i] = *--b.end();
                b.erase(--b.end());
            }
        } else b.insert(i);
    }
    fill(dp[0]+1, dp[0]+N, -inf);
    for (int k = 1; k <= m; k++) {
        fill(f.tree, f.tree+N, 0);
        int x = -inf;
        for (int i = 0; i <= n; i++)
            if (dp[k-1][i] > x) {
                dp[k-1][i] -= x;
                f.insert(i, dp[k-1][i]);
                x += dp[k-1][i];
            }
        fill(dp[k], dp[k]+N, -inf);
        int g = -inf;
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == t[k-1])
                dp[k][i] = g+f.index(i);
            else if (p[i-1] != -1) {
                g++;
                int j = f.get(f.index(p[i-1]+1));
                if (j < N) f.remove(j);
            }
        }
    }
    cout << n-m-2*dp[m][n] << "\n";
}