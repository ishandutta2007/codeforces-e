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
#define eps 1e-7
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
#define N 201
char c[ N ];
int len;
void build(){

}
void init(){
    scanf( "%s" , c );
    len = strlen( c );
}
bool can( int ti ){
    deque<int> v;
    if( ti == 0 ) v.PB( 0 );
    while( ti ){
        v.push_front( ti % 10 );
        ti /= 10;
    }
    int tlen = (int)v.size() , now = 0;
    for( int i = 0 ; i < len ; i ++ )
        if( v[ now ] == ( c[ i ] - '0' ) ){
            now ++;
            if( now == tlen ) return true;
        }
    return false;
}
void solve(){
    for( int i = 0 ; i < 1000 ; i += 8 )
        if( can( i ) ){
            printf( "YES\n%d\n" , i );
            return;
        }
    puts( "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}