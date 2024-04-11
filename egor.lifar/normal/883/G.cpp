/*
  !










*/
#pragma GCC optimize "-O3"
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
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
typedef pair <int, int> point;
const int MAXN = 300001;


int n, m, s;
vector<pair<int, int> > g[MAXN];
char ans[MAXN], ans1[MAXN];
map<pair<int, int>, vector<int> > where;
bool used[MAXN], used1[MAXN];
int as[MAXN], bs[MAXN], ts[MAXN];
int cnt = 0, cnt1 = 0;
map<pair<int, int>, bool> usedp, usedp1;


void dfs(int u) {
    cnt++;
    used[u] = true;
    for (auto h: g[u]) {
        if (!used[h.first]) {
            if (h.second == 2) {
                if (!usedp[make_pair(u, h.first)]) {
                    for (auto pos: where[make_pair(u, h.first)]) {
                        if (as[pos] == u) {
                            ans[pos] = '+';
                        } else {
                            ans[pos] = '-';
                        }
                    }
                    usedp[make_pair(u, h.first)] = true;
                    usedp[make_pair(h.first, u)] = true;
                }
            }
            dfs(h.first);
        }
    }
}


void dfs1(int u) {
    cnt1++;
    used1[u] = true;
    //cout << u + 1 << endl;
    for (auto h: g[u]) {
        if (!used1[h.first]) {
            if (h.second == 2) {
                if (!usedp1[make_pair(u, h.first)]) {
                    for (auto pos: where[make_pair(u, h.first)]) {
                        if (as[pos] == u) {
                            ans1[pos] = '-';
                        } else {
                            ans1[pos] = '+';
                        }
                    }
                    usedp1[make_pair(u, h.first)] = true;
                    usedp1[make_pair(h.first, u)] = true;
                }
                continue;
            }
            dfs1(h.first);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
  //  read(FILENAME);
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        ans[i] = '+';
        ans1[i] = '+';
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        as[i] = a;
        bs[i] = b;
        ts[i] = t;
        if (t == 2) {
            where[make_pair(a, b)].push_back(i);
            where[make_pair(b, a)].push_back(i);
        }
        if (t == 1) {
            g[a].push_back(make_pair(b, 1));
        } else {
            g[a].push_back(make_pair(b, 2));
            g[b].push_back(make_pair(a, 2));
        }
    }
    s--;
    dfs(s);
    dfs1(s);
    cout << cnt << '\n';
    for (int i = 0; i < m; i++) {
        if (ts[i] == 1) {
            continue;
        }
        cout << ans[i];
    }
    cout << '\n';
    cout << cnt1 << '\n';
    for (int i = 0; i < m; i++) {
         if (ts[i] == 1) {
            continue;
        }
        cout << ans1[i];
    }
    cout << '\n';
}