#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 110000;


int n, k;
unsigned a[MAXN];


bool read() {
    if (!(cin >> n >> k))
        return false;
    forn(i,n) {
        unsigned a1, a2, a3, a4;
        scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
        a[i] = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
    }
	return true;
}


unsigned b[MAXN];


void solve() {
    unsigned mask = 0;
    ford(bits,32) {
        mask += 1u << bits;

        forn(i,n)
            b[i] = a[i] & mask;
        sort(b, b + n);
        if (int(unique(b, b + n) - b) == k) {
            unsigned
                a1 = mask >> 24,
                a2 = (mask >> 16) & 255,
                a3 = (mask >> 8) & 255,
                a4 = mask & 255;
            printf("%d.%d.%d.%d\n", a1, a2, a3, a4);
            return;
        }
    }
    puts("-1");
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}