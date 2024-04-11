// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
#define N 101010
LL n , p , q , r , a[ N ];
void init(){
  n = getint();
  p = getint();
  q = getint();
  r = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
}
LL lmx[ N ] , lmn[ N ];
LL rmx[ N ] , rmn[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    lmx[ i ] = a[ i ];
    if( i > 1 )
      lmx[ i ] = max( lmx[ i - 1 ] , a[ i ] );
    lmn[ i ] = a[ i ];
    if( i > 1 )
      lmn[ i ] = min( lmn[ i - 1 ] , a[ i ] );
  }
  for( int i = n ; i >= 1 ; i -- ){
    rmx[ i ] = a[ i ];
    if( i < n )
      rmx[ i ] = max( rmx[ i + 1 ] , a[ i ] );
    rmn[ i ] = a[ i ];
    if( i < n )
      rmn[ i ] = min( rmn[ i + 1 ] , a[ i ] );
  }
  LL ans = 0; bool got = false;
  for( int i = 1 ; i <= n ; i ++ )
    for( LL lft : { lmn[ i ] , lmx[ i ] } )
      for( LL rgt : { rmn[ i ] , rmx[ i ] } ){
        LL vl = p * lft + q * a[ i ] + r * rgt;
        if( not got or vl > ans ){
          ans = vl;
          got = true;
        }
      }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}