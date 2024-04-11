#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

const int MAXN = 5117;

int n, a[MAXN], ans[MAXN], cnt[MAXN], m;

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i]--;
    for (int i = 0; i < n; i++)
    {
        fill(cnt, cnt + n, 0);
        m = a[i];
        for (int j = i; j < n; j++)
        {
            cnt[a[j]]++;
            if (cnt[a[j]] > cnt[m] || (cnt[a[j]] == cnt[m] && a[j] <= m))
                m = a[j];
            ans[m]++;
        }
    }
    for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
    putchar('\n');

    return 0;
}