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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 1021
int n , m , p[ N * N ] , sz[ N * N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x != y ){
    p[ x ] = y;
    sz[ y ] += sz[ x ];
  }
}
inline int trans( int xn , int xm ){
  return xn * m + xm;
}
bool in( int xn , int xm ){
  return 0 <= xn && xn < n &&
         0 <= xm && xm < m;
}
int dn[]={0,-1,0,1};
int dm[]={-1,0,1,0};
char c[ N ][ N ];
void build(){

}
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i < n * m ; i ++ ) p[ i ] = i , sz[ i ] = 1;
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , c[ i ] );
    for( int j = 0 ; j < m ; j ++ )
      if( c[ i ][ j ] == '.' ){
        for( int k = 0 ; k < 2 ; k ++ ){
          int ti = i + dn[ k ];
          int tj = j + dm[ k ];
          if( in( ti , tj ) && c[ ti ][ tj ] == '.' )
            Union( trans( i , j ) , trans( ti , tj ) );
        }
      }
  }
}
int vv[ 9 ];
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      if( c[ i ][ j ] != '.' ){
        int vvt = 0;
        for( int k = 0 ; k < 4 ; k ++ ){
          int ti = i + dn[ k ];
          int tj = j + dm[ k ];
          if( in( ti , tj ) && c[ ti ][ tj ] == '.' ){
            int xx = find_p( trans( ti , tj ) );
            bool flag = true;
            for( int _ = 0 ; _ < vvt ; _ ++ )
              if( vv[ _ ] == xx ){
                flag = false;
                break;
              }
            if( flag ) vv[ vvt ++ ] = xx;
          }
        }
        int ans = 1;
        for( int o = 0 ; o < vvt ; o ++ )
          ans += sz[ find_p( vv[ o ] ) ];
        c[ i ][ j ] = '0' + ( ans % 10 );
      }
  for( int i = 0 ; i < n ; i ++ )
    puts( c[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}