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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 1010
char c[ N ];
int cnt[ 2 ] , vl;
void build(){

}
vector<int> v;
void init(){
  int pos = 1;
  while( scanf( "%s" , c ) == 1 ){
    if( c[ 0 ] == '?' ){
      cnt[ pos ] ++;
      v.PB( pos );
    }else if( c[ 0 ] == '+' ) pos = 1;
    else if( c[ 0 ] == '-' ) pos = 0;
    else if( c[ 0 ] != '=' )
      sscanf( c , "%d" , &vl );
  }
}
void solve(){
  if( (ll)vl * cnt[ 1 ] - cnt[ 0 ] < vl ||
      cnt[ 1 ] - (ll)vl * cnt[ 0 ] > vl ){
    puts( "Impossible" );
    exit( 0 );
  }
  int nd = vl - cnt[ 1 ] + cnt[ 0 ];
  puts( "Possible" );
  for( size_t i = 0 ; i < v.size() ; i ++ ){
    if( i != 0 ){
      if( v[ i ] == 0 ) printf( " - " );
      else printf( " + " );
    }
    if( v[ i ] == 1 ){
      int x = 1;
      if( nd > 0 ){
        int got = min( vl - 1 , nd );
        nd -= got;
        x += got;
      }
      printf( "%d" , x );
    }else{
      int x = 1;
      if( nd < 0 ){
        int got = min( vl - 1 , -nd );
        nd += got;
        x += got;
      }
      printf( "%d" , x );
    }
  }
  printf( " = %d\n" , vl );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}