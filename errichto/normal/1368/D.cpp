#include <bits/stdc++.h>
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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }


int cnt[20];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		for(int bit = 0; bit < 20; ++bit) {
			if(x & (1 << bit)) {
				cnt[bit]++;
			}
		}
	}
	long long answer = 0;
	for(int i = 0; i < n; ++i) {
		int x = 0;
		for(int bit = 0; bit < 20; ++bit) {
			if(cnt[bit]) {
				x ^= (1 << bit);
				cnt[bit]--;
			}
		}
		answer += (long long) x * x;
	}
	cout << answer << endl;
}