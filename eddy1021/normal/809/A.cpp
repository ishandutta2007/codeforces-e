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
#define N 303030
LL two[ N ] , itwo[ N ];
LL inv2 = ( mod7 + 1 ) / 2;
void build(){
  two[ 0 ] = itwo[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    two[ i ] = mul( two[ i - 1 ] , 2 );
    itwo[ i ] = mul( itwo[ i - 1 ] , inv2 );
  }
}
int n , x[ N ] , s[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    x[ i ] = getint();
  sort( x , x + n );
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    s[ i ] = mul( x[ i ] , two[ n - i ] );
    if( i ) s[ i ] = add( s[ i ] , s[ i - 1 ] );
  }
  int ans = 0;
  for( int i = 1 ; i < n ; i ++ ){
    int tans = mul( s[ i - 1 ] , itwo[ n - i + 1 ] );
    ans = add( ans , mul( x[ i ] , sub( two[ i ] , 1 ) ) );
    ans = sub( ans , tans );
  }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}