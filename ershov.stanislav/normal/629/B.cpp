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

const int maxn = 500;
int n;
int cnt[2][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    char t;
    int a, b;
    scanf(" %c %d %d", &t, &a, &b);
    if (t == 'F') {
      for (int i = a; i <= b; i++) {
        cnt[0][i]++;
      }
    } else {
      for (int i = a; i <= b; i++) {
        cnt[1][i]++;
      }
    }
  }
  return true;
}

void solve() {
  int ans = 0;
  for (int i = 0; i < maxn; i++) {
    ans = max(ans, min(cnt[0][i], cnt[1][i]));
  }
  printf("%d\n", ans * 2);
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
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}