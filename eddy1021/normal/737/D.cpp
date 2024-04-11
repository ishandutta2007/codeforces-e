// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
inline void bye(){ exit(0); }
int __ = 1 , _cs;
/*********default*********/
#define N 4014
void build(){

}
int n , a[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    a[ i ] += a[ i - 1 ];
  }
}
inline int sum( int l , int r ){
  return a[ r ] - a[ l - 1 ];
}

int dp[ 2102 ][ 202 ][ 100 ][ 2 ];
bool g[ 2102 ][ 202 ][ 100 ][ 2 ];

int DP( int lft , int dlt , int k , int who ){
  if( g[ lft ][ dlt + 100 ][ k ][ who ] )
    return dp[ lft ][ dlt + 100 ][ k ][ who ];
  int res = n - lft - ( lft + dlt );
  if( res < k ) return 0;
  int ret = -1023456789;
  if( who == 0 ){
    for( int tk = k ; tk <= k + 1 ; tk ++ ){
      if( res < tk ) break;
      ret = max( ret ,
                 sum( lft + 1 , lft + tk ) -
                 DP( lft + tk , dlt - tk , tk , 1 - who ) );
    }
  }else{
    int ed = n - ( lft + dlt );
    for( int tk = k ; tk <= k + 1 ; tk ++ ){
      if( res < tk ) break;
      ret = max( ret ,
                 sum( ed - tk + 1 , ed ) -
                 DP( lft , dlt + tk , tk , 1 - who ) );
    }
  }
  g[ lft ][ dlt + 100 ][ k ][ who ] = true;
  return dp[ lft ][ dlt + 100 ][ k ][ who ] = ret;
}
void solve(){
  printf( "%d\n" , DP( 0 , 0 , 1 , 0 ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}