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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N (1 << 20)
int p[ N ] , sz[ N ];
void init_djs(){
  for( int i = 0 ; i < N ; i ++ ){
    p[ i ] = i;
    sz[ i ] = 1;
  }
}
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  x = f( x );
  y = f( y );
  if( x == y ) return;
  p[ x ] = y;
  sz[ y ] += sz[ x ];
}
void build(){

}
int n , a[ N ];
vector< int > v[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
bool gt[ N ];
void solve(){
  vector< pair<int,int> > vv;
  for( int i = 1 ; i <= n ; i ++ )
    vv.push_back( { a[ i ] , i } );
  LL ans = 0;
  {
    sort( vv.begin() , vv.end() );
    init_djs();
    for( int i = 1 ; i <= n ; i ++ )
      gt[ i ] = false;
    for( auto i : vv ){
      int now = i.second;
      gt[ now ] = true;
      LL pr = 1;
      for( int x : v[ now ] ){
        if( not gt[ x ] ) continue;
        pr += (LL)sz[ f( now ) ] * sz[ f( x ) ];
        uni( now , x );
      }
      ans += pr * i.first;
    }
  }
  {
    reverse( vv.begin() , vv.end() );
    init_djs();
    for( int i = 1 ; i <= n ; i ++ )
      gt[ i ] = false;
    for( auto i : vv ){
      int now = i.second;
      gt[ now ] = true;
      LL pr = 1;
      for( int x : v[ now ] ){
        if( not gt[ x ] ) continue;
        pr += (LL)sz[ f( now ) ] * sz[ f( x ) ];
        uni( now , x );
      }
      ans -= pr * i.first;
    }
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}