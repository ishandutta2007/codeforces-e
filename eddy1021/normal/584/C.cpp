// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 100010
int n , t , dif;
char c1[ N ] , c2[ N ] , c3[ N ];
void build(){

}
void init(){
  n = getint();
  t = getint();
  scanf( "%s%s" , c1 , c2 );
  for( int i = 0 ; i < n ; i ++ )
    if( c1[ i ] != c2[ i ] )
      dif ++;
}
char mdif( int idx ){
  for( char x = 'a' ; x ; x ++ )
    if( x != c1[ idx ] && x != c2[ idx ] )
      return x;
  return 'a';
}
void solve(){
  if( ( dif + 1 ) / 2 > t ){
    puts( "-1" );
    return;
  }
  int match = dif / 2;
  int contri = dif - dif / 2;
  while( contri < dif && contri < t )
    contri ++, match --;
  int matchu = match;
  int matchd = match;
  int difs = t - contri;
  for( int i = 0 ; i < n ; i ++ )
    if( c1[ i ] != c2[ i ] ){
      if( matchu ){
        putchar( c1[ i ] );
        matchu --;
      }else if( matchd ){
        putchar( c2[ i ] );
        matchd --;
      }else putchar( mdif( i ) );
    }else if( difs ) putchar( mdif( i ) ) , difs --;
    else putchar( c1[ i ] );
  puts( "" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}