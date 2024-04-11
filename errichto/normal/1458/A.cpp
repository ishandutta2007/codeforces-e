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

long long gcd(long long a, long long b) {
	if(a == 0) return b;
	if(b == 0) return a;
	return __gcd(a, b);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	long long g = 0;
	for(int i = 1; i < n; ++i) {
		g = gcd(g, abs(a[i] - a[i-1]));
	}
	while(m--) {
		long long b;
		scanf("%lld", &b);
		long long answer = gcd(a[0] + b, g);
		printf("%lld ", answer);
	}
	puts("");
}