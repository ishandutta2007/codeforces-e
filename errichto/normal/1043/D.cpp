#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;



int main() {
	int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int>> in(k, vector<int>(n));
    auto where = in;
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            --x;
            in[i][j] = x;
            where[i][x] = j;
        }
    }
    long long answer = 0;
    int len = 0;
    for(int heh = n - 1; heh >= 0; --heh) {
        int value = in[0][heh];
        ++len;
        if(len != 1) {
            bool ok = true;
            int should = -1;
            for(int i = 0; i < k; ++i) {
                int j = where[i][value];
                if(j + 1 < n) {
                    int val2 = in[i][j+1];
                    if(should == -1) {
                        should = val2;
                    }
                    else if(should != val2) {
                        ok = false;
                    }
                }
                else {
                    ok = false;
                }
            }
            if(!ok) {
                len = 1;
            }
        }
        answer += len;
    }
    printf("%lld\n", answer);
}