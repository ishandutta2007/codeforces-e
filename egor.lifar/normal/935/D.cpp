/*
 












 
 */
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
const int MAXN = 100001;
const int Mod = 1000000007;


inline int mul(int a, int b) {
    return (1LL * a * b) % Mod;
}


inline int add(int a, int b) {
    a += b;
    if (a >= Mod) {
        a -= Mod;
    }
    return a;
}


int powm(int x, int a) {
    if (a == 0) {
        return 1;
    } else if (a & 1) {
        return mul(powm(x, a - 1), x);
    } else {
        int g = powm(x, a >> 1);
        return mul(g, g);
    }
}




int n, m;
int a[MAXN], b[MAXN];
pair<int, int> dp[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    dp[n] = make_pair(0, 1);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] && b[i]) {
            if (a[i] > b[i]) {
                dp[i] = make_pair(1, 1);
            } else if (a[i] < b[i]) {
                dp[i] = make_pair(0, 1);
            } else {
                dp[i] = dp[i + 1];
            }
        } else {
            if (!a[i] && !b[i]) {
                long long kek = 1LL * m * (m - 1) / 2;
                kek %= Mod;
                long long kek1 = 1LL * m * m;
                kek1 %= Mod;
                dp[i] = dp[i + 1];
                dp[i].second = (1LL * dp[i].second * m) % Mod;
                dp[i].first = add(mul(dp[i].first, kek1), mul(kek, dp[i].second));
                dp[i].second = mul(dp[i].second, kek1);
            } else {
                long long kek = (a[i] == 0 ? m - b[i]: a[i] - 1);
                long long kek1 = m;
                dp[i] = dp[i + 1];
                dp[i].second = (1LL * dp[i].second * m) % Mod;
                dp[i].first = add(mul(dp[i].first, kek1), mul(kek, dp[i].second));
                dp[i].second = mul(dp[i].second, kek1);
            }
        }
    }
    cout << mul(dp[0].first, powm(dp[0].second, Mod - 2)) << '\n';
}