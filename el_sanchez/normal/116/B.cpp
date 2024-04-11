#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)11000;

using namespace std;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, ans = 0;
    scanf("%d%d\n", &n, &m);
    char c[n][m];
    forn(i, n) {
        forn(j, m)
            scanf("%c", &c[i][j]);
        scanf("\n");
    }

    forn(i, n) {
        forn(j, m)
            if (c[i][j] == 'P') {
                if (i > 0 && c[i - 1][j] == 'W') {
                    c[i - 1][j] = '.';
                    ans++;
                    continue;
                }
                if (i+1 < n && c[i + 1][j] == 'W') {
                    c[i + 1][j] = '.';
                    ans++;
                    continue;
                }
                if (j > 0 && c[i][j - 1] == 'W') {
                    c[i][j -1] = '.';
                    ans++;
                    continue;
                }
                if (j+1 < m && c[i][j + 1] == 'W') {
                    c[i][j + 1] = '.';
                    ans++;
                    continue;
                }
            }
    }

    cout << ans;

    return 0;
}