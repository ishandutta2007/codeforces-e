// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
void build(){

}
char c[ 1010101 ];
int len , mxd;
vector< pair<int,int> > vv[ 1010101 ];
void init(){
  scanf( "%s" , c );
  len = strlen( c );
}
int ptr;
void go( int d ){
  if( ptr >= len ) return;
  //printf( "%d %d\n" , d , ptr );
  mxd = max( mxd , d );
  int l = ptr;
  while( ptr < len && isalpha( c[ ptr ] ) ) ptr ++;
  vv[ d ].push_back( { l , ptr - 1 } );
  ptr ++;
  int chd = 0;
  while( ptr < len && isdigit( c[ ptr ] ) ){
    chd = chd * 10 + c[ ptr ] - '0';
    ptr ++;
  }
  ptr ++;
  for( int i = 0 ; i < chd ; i ++ )
    go( d + 1 );
}
void solve(){
  while( ptr < len )
    go( 1 );
  printf( "%d\n" , mxd );
  for( int i = 1 ; i <= mxd ; i ++ )
    for( size_t j = 0 ; j < vv[ i ].size() ; j ++ ){
      for( int k = vv[ i ][ j ].first ; k <= vv[ i ][ j ].second ; k ++ )
        putchar( c[ k ] );
      printf( "%c" , " \n"[ j + 1 == vv[ i ].size() ] );
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