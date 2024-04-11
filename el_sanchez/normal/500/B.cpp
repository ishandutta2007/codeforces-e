#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 333;

int n, tmr;
int a[MAXN][MAXN];
int used[MAXN];
vi p;
int pos;
vi sorted;
string s;

void dfs(int v) {
	used[v] = tmr;
	forn(w, n)
		if (a[v][w] && used[w] != tmr)
			dfs(w);
}

int main() {

	cin >> n;
	p.resize(n);
	forn(i, n)
		cin >> p[i];
		
	forn(i, n) {
		cin >> s;
		forn(j, n)
			a[i][j] = s[j] == '1';
	}
	
	forn(i, n)
		if (used[i] == 0) {
			tmr++;
			dfs(i);	
			
			sorted.clear();
			forn(j, n)
				if (used[j] == tmr)
					sorted.pb(p[j]);
			sort(all(sorted));
			pos = 0;
			forn(j, n)
				if (used[j] == tmr) {
					p[j] = sorted[pos];
					pos++;	
				}
		}
		
	forn(i, n)
		cout << p[i] << ' ';
	cout << '\n';
	
	return 0;
}