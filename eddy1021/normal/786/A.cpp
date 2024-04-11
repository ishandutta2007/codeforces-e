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
#define N 7777
void build(){

}
int n , c[ 2 ];
vector<int> v[ 2 ];
void init(){
  n = getint();
  for( int i = 0 ; i < 2 ; i ++ ){
    c[ i ] = getint();
    for( int j = 0 ; j < c[ i ] ; j ++ )
      v[ i ].push_back( getint() );
    sort( v[ i ].begin() , v[ i ].end() );
    v[ i ].resize( unique( v[ i ].begin() , v[ i ].end() ) - v[ i ].begin() );
    c[ i ] = (int)v[ i ].size();
  }
}
pair<int,int> que[ N * 10 ];
int qf , qt;
// 1 win 2 lose 0 loop
inline int Sub( int a , int b ){
  a -= b;
  return a > 0 ? a : a + n;
}
int dp[ N ][ 2 ];
int cc[ N ][ 2 ];
void solve(){
  dp[ 1 ][ 0 ] = 2;
  dp[ 1 ][ 1 ] = 2;
  que[ qt ++ ] = { 1 , 0 };
  que[ qt ++ ] = { 1 , 1 };
  for( int i = qf ; i < qt ; i ++ ){
    int at , who;
    tie( at , who ) = que[ i ];
    if( dp[ at ][ who ] == 2 ){
      for( int stp : v[ 1 - who ] ){
        int nxt = Sub( at , stp );
        if( dp[ nxt ][ 1 - who ] ) continue;
        dp[ nxt ][ 1 - who ] = 1;
        que[ qt ++ ] = { nxt , 1 - who };
      }
    }else{
      for( int stp : v[ 1 - who ] ){
        int nxt = Sub( at , stp );
        if( dp[ nxt ][ 1 - who ] ) continue;
        cc[ nxt ][ 1 - who ] ++;
        if( cc[ nxt ][ 1 - who ] == c[ 1 - who ] ){
          dp[ nxt ][ 1 - who ] = 2;
          que[ qt ++ ] = { nxt , 1 - who };
        }
      }
    }
  }
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 2 ; j <= n ; j ++ ){
      if( dp[ j ][ i ] ) printf( dp[ j ][ i ] == 1 ? "Win" : "Lose" );
      else printf( "Loop" );
      printf( "%c" , " \n"[ j == n ] );
    }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}