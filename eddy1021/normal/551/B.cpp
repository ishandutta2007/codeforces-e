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
#define eps 1e-18
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
char a[ N ] , b[ N ] , c[ N ];
int cnt[ 26 ] , nd1[ 26 ] , nd2[ 26 ];
int lena , lenb , lenc;
void build(){

}
void init(){
    scanf( "%s%s%s" , a , b , c );
    lena = strlen( a );
    for( int i = 0 ; i < lena ; i ++ )
        cnt[ a[ i ] - 'a' ] ++;
    lenb = strlen( b );
    for( int i = 0 ; i < lenb ; i ++ )
        nd1[ b[ i ] - 'a' ] ++;
    lenc = strlen( c );
    for( int i = 0 ; i < lenc ; i ++ )
        nd2[ c[ i ] - 'a' ] ++;
}
int cal( int ti ){
    int tk = lena / lenc;
    for( int i = 0 ; i < 26 ; i ++ ){
        if( cnt[ i ] < nd1[ i ] * ti ) return 0;
        if( nd2[ i ] ){
            tk = min( tk , ( cnt[ i ] - nd1[ i ] * ti ) / nd2[ i ] );
        }
    }
    return ti + tk;
}
void solve(){
    int bst = 0 , bsti = 0;
    for( int i = 0 ; i <= lena / lenb ; i ++ ){
        int tmp = cal( i );
        if( tmp > bst ){
            bst = tmp;
            bsti = i;
        }
    }
    bst -= bsti;
    for( int i = 0 ; i < bsti ; i ++ ) printf( "%s" , b );
    for( int i = 0 ; i < bst ; i ++ ) printf( "%s" , c );
    for( int i = 0 ; i < 26 ; i ++ )
        if( nd1[ i ] ){
            for( int j = 0 ; j < bsti * nd1[ i ] ; j ++ )
                cnt[ i ] --;
        }
    for( int i = 0 ; i < 26 ; i ++ )
        if( nd2[ i ] ){
            for( int j = 0 ; j < bst * nd2[ i ] ; j ++ )
                cnt[ i ] --;
        }
    for( int i = 0 ; i < 26 ; i ++ )
        while( cnt[ i ] ){
            putchar( i + 'a' );
            cnt[ i ] --;
        }
    puts( "" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}