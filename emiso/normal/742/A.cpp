#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d",&n);

    if(n == 0) printf("1\n");
    else  if(n % 4 == 1) printf("8\n");
    else if(n % 4 == 2) printf("4\n");
    else if(n % 4 == 3) printf("2\n");
    else if(n % 4 == 0) printf("6\n");
    return 0;
}