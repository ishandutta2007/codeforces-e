// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
#define INF 1023456789ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
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
#define N 110
int n;
char c[ N ];
void build(){

}
void init(){
    n = getint();
    scanf( "%s" , c + 1 );
}
bool good(){
    for( int i = 1 ; i <= n ; i ++ )
        if( c[ i ] == '*' )
            for( int j = 1 ; j <= n ; j ++ ){
                if( i + 4 * j > n ) break;
                if( c[ i + j ] == '*' &&
                    c[ i + j * 2 ] == '*' &&
                    c[ i + j * 3 ] == '*' &&
                    c[ i + j * 4 ] == '*' )
                    return true;
            }
    return false;
}
void solve(){
    if( good() ) puts( "yes" );
    else puts( "no" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}