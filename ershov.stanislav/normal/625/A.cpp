#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

int rnd(int x) {
  return myrand() % x;
}

ll n;
ll a, b, c;

bool read() {
  if (scanf(LLD " " LLD " " LLD " " LLD, &n, &a, &b, &c) < 3) {
    return false;
  }
  return true;
}

void solve() {
  ll ans = 0;
  if (a < b - c) {
    ans = n / a; 
  } else {
    if (n >= b) {
      ans += (n - b) / (b - c) + 1;
    }
    n -= ans * (b - c);
    ans += n / a;
  }
  printf(LLD "\n", ans);
}

int main() {
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}