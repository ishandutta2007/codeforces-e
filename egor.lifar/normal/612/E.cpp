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
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
  
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 1000228;


int n;
vector<vector<int> > cycles[MAXN];
vector<int> cycle;
int used[MAXN];
int ans[MAXN];
int p[MAXN];


void dfs(int u) {
    cycle.push_back(u);
    used[u] = 1;
    int h = p[u];
    if (!used[h]) {
        dfs(h);
    }
}


inline void update(vector<int> &v) {
    for (int i = 0; i < sz(v); i++) {
        ans[v[i]] = v[(i + 1) % sz(v)];
    }
}


int main(){
    n = readInt();
    for (int i = 1; i <= n; i++) {
        p[i] = readInt();
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cycle.clear();
            dfs(i);
            cycles[sz(cycle)].push_back(cycle);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 && sz(cycles[i]) % 2 == 1) {
            writeWord("-1\n");
            return 0;
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 0; j < sz(cycles[i]); j++) {
                vector<int> g;
                for (int q = 0; q < (i >> 1); q++) {
                    g.push_back(cycles[i][j][q]);
                    g.push_back(cycles[i][j][q + 1 + (i >> 1)]);
                }
                g.push_back(cycles[i][j][i >> 1]);
                update(g);
            }
        } else {
            for (int j = 0; j < sz(cycles[i]); j += 2) {
                vector<int> g;
                for (int q = 0; q < sz(cycles[i][j]); q++) {
                    g.push_back(cycles[i][j][q]);
                    g.push_back(cycles[i][j + 1][q]);
                }
                update(g);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        writeInt(ans[i], ' ');
    }
    writeChar('\n');
    return 0;
}