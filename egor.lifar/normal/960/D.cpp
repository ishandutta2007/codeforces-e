/*
 












 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
#include <iostream>
#include <complex>
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
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
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
const string FILENAME = "input";
//WULD! NAH! KEST!
const int MAXN = 100001;


int q;
long long shift[100];
long long shift1[100];


long long getwho(long long x) {
    int cnt = 0;
    long long x1 = x;
    while (x1 >= 1) {
        cnt++;
        x1>>= 1;
    }
    //2 ** level
    //2 ** (level + 1) - 1
    long long len = (1LL << (cnt - 1));
    long long pos = x - (1LL << (cnt - 1));
    pos -= shift[cnt];
    pos %= len;
    if (pos < 0) {
        pos += len;
    }
    return pos + (1LL << (cnt - 1));
}


long long getprev(long long x) {
    int cnt = 0;
    long long x1 = x;
    while (x1 >= 1) {
        cnt++;
        x1>>= 1;
    }
    //2 ** level
    //2 ** (level + 1) - 1
    long long len = (1LL << (cnt - 1));
    long long pos = x - (1LL << (cnt - 1));
    pos += shift1[cnt];
    pos %= len;
    return (pos + (1LL << (cnt - 1))) >> 1;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> q;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 1) {
            long long x, k;
            cin >> x >> k;
            int cnt = 0;
            long long x1 = x;
            while (x1 >= 1) {
                cnt++;
                x1>>= 1;
            }
            shift[cnt] += k;
            shift[cnt] %= (1LL << (cnt - 1));
            if (shift[cnt] < 0) {
                shift[cnt] += (1LL << (cnt - 1));
            }
        } else if (t == 2) {
            long long x, k;
            cin >> x >> k;
            long long x1 = x;
            int cnt = 0;
            while (x1 >= 1) {
                cnt++;
                x1>>= 1;
            }
            shift1[cnt] += k;
            shift1[cnt] %= (1LL << (cnt - 1));
            if (shift1[cnt] < 0) {
                shift1[cnt] += (1LL << (cnt - 1));
            }
        } else {
            long long x;
            cin >> x;
            long long x1 = x;
            int cnt = 0;
            while (x1 >= 1) {
                cnt++;
                x1>>= 1;
            }
            long long len = 1LL << (cnt - 1);
            x -= len;
            x = x + shift[cnt];
            if (x >= len) {
                x -= len;
            }
            x += len;
            while (x >= 1) {
                cout << getwho(x) << ' ';
                x = getprev(x);
            }
            cout << '\n';
        }
    }
    return 0;     
}