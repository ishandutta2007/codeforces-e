#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, A[N], Ans ; 
signed main()
{
	n = gi() ; rep( i, 1, n ) A[i] = gi() ; 
	rep( i, 1, n ) Ans += A[i] * ( n - A[i] + 1 ) ;
	rep( i, 2, n ) {
		int ll = min( A[i], A[i - 1] ), rr = max( A[i], A[i - 1] ) ;
		Ans -= ll * ( n - rr + 1 ) ;
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}