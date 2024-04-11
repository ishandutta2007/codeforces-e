#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin >> n;
    
    int fixed = -1;
    set<int> s;
    
    int total = 0;
    
    forn(i,n)
    {
        int x;
        cin >> x;
        if (x == fixed && s.size() == 1 && esta(x,s))
            continue;
        else if (x == fixed)
        {
            total++;
            s = {x};
            continue;
        }
        else
        {
            total++;
            if (!(s.size() == 1 && esta(x,s)))
                s.insert(fixed);
            fixed = x;
        }
    }

    cout << total << "\n";
        
    return 0;
}