#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int main() {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	
	printf("%.18lf\n", a*a*a*sqrt(2)/12 + b*b*b/3/sqrt(2) + c * c * c * 0.301502832395831588);
	
	//printf("%.18lf\n", (38.546168065709 - a*a*a*sqrt(2)/12 - b*b*b/3/sqrt(2)) / c / c / c);
	return 0;
}