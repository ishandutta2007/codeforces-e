
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (no<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int t, n;
string s;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--){
      cin >> n >> s;
      string a1, a2;
      //reverse(all(s));
      int g = -1;
      for(char c : s){
        if(c == '0'){
          a1 += '0';
          a2 += '0';
        }
        else if(c == '1'){
          if(g == -1){
            a1 += '1';
            a2 += '0';
            g = 0;
          }
          else {
            if(g == 0){
              a2 += '1';
              a1 += '0';
            }
            else {
                 a1 += '1';
              a2 += '0';
            }
          }
        }
        else {
          if(g == 0){
            a2 += '2';
            a1 += '0';
          }
          else if(g == 1){
              a2 += '0';
            a1 += '2';
          }
          else {
              a1 += '1';
            a2 += '1';
          }
        }
      }
      cout << a1 << ln << a2 << ln;
  }

}