#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E5+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int a, b, n, p[MAXN], e[MAXN], last;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d\n", &n);
    forn(i, n) {
        scanf("%d", &e[i]);
        p[i] = e[i];
    }

    a = 0;
    b = n-1;
    last = -1;
    while (a < b) {
        if (p[a] < p[b]) {
            p[b] -= p[a];
            p[a] = 0;
            a++;
            last = 1;
            continue;
        }
        if (p[a] > p[b]) {
            p[a] -= p[b];
            p[b] = 0;
            b--;
            last = -1;
            continue;
        }
        p[a] = 0;
        p[b] = 0;
        a++;
        b--;
        last = -1;
    }

    if (a == b) {
        if (last == 1)
            a--;
        else
            b++;
    } else {
        a--;
        b++;
    }

    printf("%d %d", a + 1, n - b);

    return 0;
}