#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;
int n, P, ans, binom[maxn][maxn], fact[maxn];
int f[maxn][maxn * maxn], d[maxn * maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d", &n, &P);
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    f[0][n * (n - 1) / 2] = 1;
    for (int i = 1; i <= n; i++) {
        memset(d, 0, sizeof(d));
        for (int j = 0; j <= n * (n - 1); j++) if (f[i - 1][j]) {
            red(d[j + 1] += f[i - 1][j] - P);
            red(d[j + i + 1] -= f[i - 1][j]);
            red(d[j + i + 1] -= f[i - 1][j]);
            red(d[j + 2 * i + 1] += f[i - 1][j] - P);
        }
        for (int j = 1; j <= n * n; j++) {
            red(d[j] += d[j - 1] - P);
        }
        for (int j = 1; j <= n * n; j++) {
            red(d[j] += d[j - 1] - P);
        }
        for (int j = 0; j <= n * (n - 1); j++) {
            f[i][j] = d[j + i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n * (n - 1); ~j; j--) {
            red(f[i][j] += f[i][j + 1] - P);
        }
    }
    for (int i = 0; i < n; i++) {
        int t = 1LL * binom[n][i] * fact[i] % P;
        for (int x = 1; x <= n - i; x++) {
            for (int y = x + 1; y <= n - i; y++) {
                ans = (ans + 1LL * t * f[n - i - 1][n * (n - 1) / 2 + y - x + 1]) % P;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}