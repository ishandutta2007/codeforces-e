#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>

 
 
using namespace std;
 
 
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
 
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
 
/** Read */
 
static const int buf_size = 4096;
 
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}
 
inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}
 
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
 
/** Write */
 
static int write_pos = 0;
static char write_buf[buf_size];
 
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
 
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
 
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
 
inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}
 
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const double eps = 1e-9;
const int MAXN = 2228;
const int INF = 2000000000;
const int MOD = 1000000007;
const long long LINF = 1000000000000000000LL;


int n, m, W;
vector<int> v[MAXN];
vector<int> comp;
int w[MAXN];
int b[MAXN];
bool used[MAXN];
int dp[MAXN][2];


void dfs(int u) {
    used[u] = 1;
    comp.push_back(u);
    for (auto h: v[u]) {
        if (!used[h]) {
            dfs(h);
        }
    }
}


int main() {
    n = readInt(), m = readInt(), W = readInt();
    for (int i = 0; i < n; i++) {
        w[i] = readInt();    
    }
    for (int i = 0; i < n; i++) {
        b[i] = readInt();
    }
    for (int i = 0; i < m; i++) {
        int s = readInt(), f = readInt();
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        comp.clear();
        dfs(i);
        int sum = 0, sum1 = 0;
        for (auto a: comp) {
            sum += w[a];
            sum1 += b[a];
            for (int prev = 0; prev + w[a] <= W; prev++) {
                dp[prev + w[a]][1] = max(dp[prev + w[a]][1], dp[prev][0] + b[a]);
            }
        }
        for (int prev = 0; prev + sum <= W; prev++) {
            dp[prev + sum][1] = max(dp[prev + sum][1], dp[prev][0] + sum1);
        }
        for (int j = 0; j <= W; j++) {
            dp[j][1] = max(dp[j][1], dp[j][0]);
            swap(dp[j][1], dp[j][0]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, dp[i][0]);
    }
    writeInt(ans, '\n');
    return 0;
}