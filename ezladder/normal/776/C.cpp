#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>

using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define XX first
#define YY second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
const double pi = acos(-1.0);

const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

ll n, k;
ll a[100007];
map<ll, int> was;

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));

    ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("integral.in", "r", stdin);
        //freopen("integral.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    was[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        if (k == -1){
            ans += was[sum - 1];
            ans += was[sum + 1];
        } else
        if (k == 1){
            ans += was[sum - 1];
        } else {
            ans += was[sum - 1];
            ll now = k;
            while(1){
                if (abs(now) > (ll)1e16) break;
                ans += was[sum - now];
                now *= (ll)k;
            }
        }
        was[sum]++;
    }
    cout << ans;
}