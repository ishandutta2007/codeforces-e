#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 5e5 + 100;

int n, s;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &s) < 2) {
    return false;
  }
  s--;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

bool used[maxn];

void solve() {
  memset(used, 0, sizeof(used));
  int cntbad = 0;
  int allbad = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if ((i == s) ^ (a[i] == 0)) {
      cntbad++;
      allbad++;
    } else {
      used[a[i]] = 1;
      v.pb(a[i]);
    }
  }
  sort(v.begin(), v.end());
  int j = 0;
  while (used[j] || cntbad) {
    if (!used[j]) {
      cntbad--;
    }
    j++;
  }
  while (sz(v) && v.back() > j) {
    v.pop_back();
    cntbad++;
    allbad++;
    while (used[j] || cntbad) {
      if (!used[j]) {
        cntbad--;
      }
      j++;
    }
  }
  printf("%d\n", allbad);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}