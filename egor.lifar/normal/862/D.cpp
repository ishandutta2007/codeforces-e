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
#define ends ends228
#define begins begins228


int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        s += '0';
    }
    assert(sz(s) == n);
    cout << '?' << ' ' << s << endl;
    int a;
    cin >> a;
    a = n - a;
    s[0] = '1';
    assert(sz(s) == n);
    cout << '?' << ' ' << s << endl;
    int b;
    cin >> b;
    b = n - b;
    int pos0, pos1;
    if (a > b) {
        pos0 = 1;
        int l = 1;
        int r = n - 1;
        while (l != r) {
            int mid = (l + r) >> 1;
            s.clear();
            for (int i = 0; i < n; i++) {
                s += '0';
            }
            for (int j = 1; j <= mid; j++) {
                s[j] = '1';
            }
            assert(sz(s) == n);
            cout << '?' << ' ' << s << endl;
            int c;
            cin >> c;
            c = n - c;
            if (c == a - mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        pos1 = l + 1;
    } else {
        s.clear();
        for (int i = 0; i < n; i++) {
            s += '1';
        }
        cout << '?' << ' ' << s << endl;
        cin >> b;
        b = n - b;
        pos1 = 1;
        int l = 1;
        int r = n - 1;
        while (l != r) {
            int mid = (l + r) >> 1;
            s.clear();
            for (int i = 0; i < n; i++) {
                s += '1';
            }
            for (int j = 1; j <= mid; j++) {
                s[j] = '0';
            }
            assert(sz(s) == n);
            cout << '?' << ' ' << s << endl;
            int c;
            cin >> c;
            c = n - c;
            if (c == b - mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        pos0 = l + 1;
    }
    cout << '!' << ' ' << pos0 << ' ' << pos1 << endl;
    return 0;
}