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

void test_case() {
	int n;
	long long W;
	scanf("%d%lld", &n, &W);
	long long already = 0;
	vector<int> print;
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		if(already + x <= W) {
			already += x;
			print.push_back(i);
		}
		else if(x <= W && x >= (W + 1) / 2) {
			print = {i};
			already = x;
			// break;
		}
	}
	if(already >= (W + 1) / 2) {
		printf("%d\n", (int) print.size());
		for(int i : print) printf("%d ", i);
		puts("");
	}
	else {
		puts("-1");
	}
}
		

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}