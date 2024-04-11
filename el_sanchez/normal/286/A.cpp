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
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 100500;  

int n;
int nxt[MAXN], p[MAXN];
                          
int main() {

	cin >> n;
	if (n % 4 == 2 || n % 4 == 3) {
		cout << -1;
		return 0;
	}
	
	if (n % 4 == 1) {
		p[n / 2] = n / 2;	
	}
	
	for (int i = 0; i < n / 2; i += 2) {
		p[i] = i + 1;
		p[i + 1] = n - i - 1;	
		p[n - i - 1] = n - i - 2;
		p[n - i - 2] = i;	
	}
	
	forn(i, n)
		cout << p[i] + 1 << ' ';
	
	
	return 0;
}