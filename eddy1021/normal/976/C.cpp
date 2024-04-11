// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=1000000007LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add(LL _x, LL _y, LL _mod=mod7){
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline LL sub(LL _x, LL _y, LL _mod=mod7){
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
LL mypow(LL _a, LL _x, LL _mod){
  if(_x == 0) return 1LL;
  LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
LL mymul(LL _a, LL _x, LL _mod){
  if(_x == 0) return 0LL;
  LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
int n;
vector< tuple<int,int,int> > v;
void init(){
  n=getint();
  v.resize(n);
  for(int i=0; i<n; i++){
    get<0>(v[i]) = getint();
    get<1>(v[i]) = getint();
    get<2>(v[i]) = i + 1;
  }
  sort(v.begin(), v.end(), 
       [&](tuple<int,int,int>& t1, tuple<int,int,int>& t2){
        if(get<0>(t1) != get<0>(t2)) return get<0>(t1) < get<0>(t2);
        return get<1>(t1) > get<1>(t2);
       });
}
void solve(){
  int bst=-1, bi=-1;
  for(auto i: v){
    if(bst >= get<1>(i)){
      printf("%d %d\n", get<2>(i), bi);
      exit(0);
    }
    if(get<1>(i) > bst){
      bst=get<1>(i);
      bi=get<2>(i);
    }
  }
  puts("-1 -1");
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}