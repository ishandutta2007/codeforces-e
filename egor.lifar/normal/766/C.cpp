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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 1001;
const int Mod = 1000000007;


int n;
string s;
int a[26];
bool can[MAXN][MAXN];
int cnts[MAXN];
int maxlen[MAXN];
int mincnt[MAXN];


int main() {
    cin >> n >> s;
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int minimum = n;
        for (int j = i; j < n; j++) {
            minimum = min(minimum, a[s[j] - 'a']);
            if (minimum < j - i + 1) {
                break;
            }
            can[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        mincnt[i] = n;
        maxlen[i] = -1;
        cnts[i] = 0;
        if (can[0][i]) {
            cnts[i]++;
            maxlen[i] = i + 1;
            mincnt[i] = 1; 
        }
        for (int j = i - 1; j >= 0; j--) {
            if (can[j + 1][i]) {
                cnts[i] += cnts[j];
                cnts[i] %= Mod;
                maxlen[i] = max(maxlen[i], max(maxlen[j], i - j));
                mincnt[i] = min(mincnt[i], mincnt[j] + 1);
            }
        }
    }
    cout << cnts[n - 1] << endl;
    cout << maxlen[n - 1] << endl;
    cout << mincnt[n - 1] << endl;
    return 0;
}