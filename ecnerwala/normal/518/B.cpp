#include<bits/stdc++.h>
using namespace std; int a[300], b[300]; int main() { string s,t; cin >> s >> t; for( char c : s) a[c] ++; for( char d : t) b[d] ++; int l = 0; for( int c = 0; c < 200; c++) l += min (a[c], b[c]); int r = 0; for( int i = 0; i < 26; i++) r += min(a['a'+i] + a['A'+i], b['a'+i]+b['A'+i]); r-=l; cout << l << ' ' << r << '\n'; }