#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long

#define all(x) (x).begin(), (x).end()

// these to_string headers are taken from tourist on codeforces

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("input.in");
#endif

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; fin >> t;
    while (t--) {
        int n; string s; fin >> n >> s;
        int a = 0, b = 0, abs = 0, len = 0;
        vector<int> delta(n), high(n), low(n);
        high[0] = low[0] = 0;

        for (int i = 0; i < n-1; i++) {
            if (s[i] == '>') {
                delta[i] = a-1-abs;
                abs = --a; len = 0;
            } else {
                delta[i] = 1;
                abs++; len++;
                if (abs >= a && abs <= b) {
                    delta[i-len]--; abs--; a--;
                }
                b = max(abs, b);
            }
        }

        for (int i = 1; i < n; i++)
            low[i] = low[i-1]+delta[i-1];

        len = 0; abs = 0; a = 0; b = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '<') {
                delta[i] = b+1-abs;
                abs = ++b; len = 0;
            } else {
                delta[i] = -1;
                abs--; len++;
                if (abs >= a && abs <= b) {
                    delta[i-len]++; abs++; b++;
                }
                a = min(abs, a);
            }
        }

        for (int i = 1; i < n; i++)
            high[i] = high[i-1]+delta[i-1];

        int m = inf;
        for (auto& x : low) m = min(m, x-1);
        for (auto& x : low) x -= m;

        m = inf;
        for (auto& x : high) m = min(m, x-1);
        for (auto& x : high) x -= m;

        for (auto& x : low) cout << x << " ";
        cout << "\n";
        for (auto& x : high) cout << x << " ";
        cout << "\n";
    }
}